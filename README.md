# Custom_Qt5_Rviz2
In this repository is an example on how to implement the `RenderPanel` of [`rviz2`](https://github.com/ros2/rviz). This is a workaround and it's not the best solution but it's the only way I found to work.
For this to work, I made a small changes to the `rviz` source code, these can be found on my [fork](https://github.com/MartiBolet/rviz).
This example tries to be an ROS2 version of this [tutorial](http://docs.ros.org/en/indigo/api/librviz_tutorial/html/index.html#).
![](./img/screenshot.png)

## Compile & run
To compile the project:
```
cd $HOME
mkdir myviz_ws && cd myviz_ws
git clone https://github.com/MartiBolet/rviz
git clone https://github.com/MartiBolet/Custom_Qt5_Rviz2
# Build
colcon build --symlink-install
# Install
source ./install/setup.bash
```
To run the window:
```
ros2 run myviz myviz
```

## Error `libGL error: failed to create drawable`
If there is an error like `libGL error: failed to create drawable` and the `RenderPanel` doesn't show anything, try to:
```
export LIBGL_ALWAYS_SOFTWARE=1
```
From this [answer](https://answers.ros.org/question/286985/libgl-error-failed-to-create-drawable/) and this [tutorial](http://wiki.ros.org/rviz/Troubleshooting)

## Contributors:
Co-workers: [@albertarla](https://github.com/albertarla), [@iggyrrieta](https://github.com/iggyrrieta).
All contributions are welcome and open to discussion.

## License
Apache License 2.0
