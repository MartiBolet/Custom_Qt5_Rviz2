# Custom_Qt5_Rviz2
In this repository is an example on how to implement the `RenderPanel` of [`rviz2`](https://github.com/ros2/rviz). This is a workaround and it's not the best solution but it works.
For this to work, I made a small changes to the `rviz` source code, that these is included in this repository.

![](./img/screenshot.png)

## Error `libGL error: failed to create drawable`
If there is an error like `libGL error: failed to create drawable` and the `RenderPanel` doesn't show anything, try to:
```
export LIBGL_ALWAYS_SOFTWARE=1
```
From this [answer](https://answers.ros.org/question/286985/libgl-error-failed-to-create-drawable/) and this [tutorial](http://wiki.ros.org/rviz/Troubleshooting)

## Contributors:
Co-workers: [@albertarla](https://github.com/albertarla), [@iggyrrieta](https://github.com/iggyrrieta).

## License
Apache License 2.0
