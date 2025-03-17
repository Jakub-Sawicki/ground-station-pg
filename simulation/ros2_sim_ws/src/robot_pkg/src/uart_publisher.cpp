#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <sstream>

class UARTPublisher : public rclcpp::Node {
public:
    UARTPublisher() : Node("uart_publisher") {
        subscription_ = this->create_subscription<geometry_msgs::msg::Twist>(
            "/cmd_vel", 10, std::bind(&UARTPublisher::cmd_vel_callback, this, std::placeholders::_1));

        uart_fd_ = open("/dev/pts/4", O_WRONLY | O_NOCTTY);
        if (uart_fd_ == -1) {
            RCLCPP_ERROR(this->get_logger(), "Nie udało się otworzyć portu UART");
        } else {
            struct termios options;
            tcgetattr(uart_fd_, &options);
            cfsetispeed(&options, B115200);
            cfsetospeed(&options, B115200);
            options.c_cflag = CS8 | CLOCAL | CREAD;
            tcsetattr(uart_fd_, TCSANOW, &options);
        }
    }

    ~UARTPublisher() {
        if (uart_fd_ != -1) {
            close(uart_fd_);
        }
    }

private:
    void cmd_vel_callback(const geometry_msgs::msg::Twist::SharedPtr msg) {
        if (uart_fd_ == -1) return;

        std::ostringstream ss;
        ss << msg->linear.x << "," << msg->angular.z << "\n";
        std::string data = ss.str();

        write(uart_fd_, data.c_str(), data.length());
        RCLCPP_INFO(this->get_logger(), "Wysłano przez UART: %s", data.c_str());
    }

    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_;
    int uart_fd_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<UARTPublisher>());
    rclcpp::shutdown();
    return 0;
}
