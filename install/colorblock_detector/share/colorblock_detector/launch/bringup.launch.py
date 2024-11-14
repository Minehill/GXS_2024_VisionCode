import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    config = os.path.join(
        get_package_share_directory('colorblock_detector'), 'config', 'colorblock.yaml')
        
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

    launch_description = LaunchDescription(
        [qrcode, colordetect]
    )

    return launch_description
