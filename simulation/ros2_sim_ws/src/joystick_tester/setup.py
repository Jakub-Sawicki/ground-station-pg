from setuptools import find_packages, setup

package_name = 'joystick_tester'

setup(
    name=package_name,
    version='0.0.1',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Kuba',
    maintainer_email='kuba_sawicki@onet.pl',
    description='Simple GUI for testing joystick',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'joystick_test = joystick_tester.joystick_test:main'
        ],
    },
)
