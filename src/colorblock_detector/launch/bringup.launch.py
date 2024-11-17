import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    config = os.path.join(
        get_package_share_directory('colorblock_detector'), 'config', 'colorblock.yaml')

    camera_pub = Node(
        package="camera_driver",
        executable="image_publisher",
        output="screen"
    )

    qrcode = Node(
        package="binary_detector",
        executable="binary",
        output="screen"
    )

    colordetect = Node(
        package="colorblock_detector",
        executable="colorblock",
        output="screen",
        parameters=[config]
    
    )

    config_ = os.path.join(
    get_package_share_directory('gxs_serial_driver'), 'config', 'serial_driver.yaml')

    gxs_serial_driver_node = Node(
        package='gxs_serial_driver',
        executable='gxs_serial_driver_node',
        namespace='',
        output='screen',
        emulate_tty=True,
        parameters=[config_],
    )

    launch_description = LaunchDescription(
        [qrcode, colordetect, camera_pub, gxs_serial_driver_node]
    )

    return launch_description
