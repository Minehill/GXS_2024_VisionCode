from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='line_follow',
            executable='lf',
            name='line_follower',
            output='screen',
            parameters=[
                {'lower_white': [15, 130, 130]},
                {'upper_white': [100, 190, 190]},
                {'min_line_length': 30},
                {'max_line_gap': 60},
                {'if_debug': False}
            ]
        )
    ])