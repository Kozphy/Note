# Optimization
###### tags: `python module`

The default configuration isn’t optimized for throughput. By default, it tries to walk the middle way between many short tasks and fewer long tasks, a compromise between throughput and fair scheduling.

If you have strict fair scheduling requirements, or want to optimize for throughput then you should read the [**Optimizing Guide**](https://docs.celeryq.dev/en/stable/userguide/optimizing.html#guide-optimizing).