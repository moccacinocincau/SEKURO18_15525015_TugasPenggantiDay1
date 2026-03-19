from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():

    return LaunchDescription([

        Node(
            package='15525015_Shopee',
            executable='MyA_Publisher',
	    name='myA_publisher',
            output='screen'
        ),
        Node(
            package='15525015_Shopee',
            executable='MyA_Subscriber',
	    name='myA_subscriber',
            output='screen'
        )
    ])
