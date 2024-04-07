#Software

- [[#Intro Prometheus|Intro Prometheus]]
- [[#what is metrics|what is metrics]]
	- [[#what is metrics#Types of Metrics|Types of Metrics]]
		- [[#Types of Metrics#Gauges|Gauges]]
		- [[#Types of Metrics#Counters|Counters]]
		- [[#Types of Metrics#Histograms|Histograms]]
## Intro Prometheus
**Prometheus** is a powerful tool in the field of `software monitoring and alerting`. 

It is widely used for gathering `metrics` and generating alerts in many cloud-native environments. 

Prometheus allows developers and system administrators to monitor various aspects of their applications, services, and infrastructure. 

By collecting and storing time-series data, Prometheus enables real-time analysis, visualization, and alerting based on predefined thresholds. 

Its flexibility, scalability, and integration capabilities make it a popular choice for monitoring and observability in modern software systems.

## what is metrics
**Metrics** in the context of **Prometheus** refer to `quantitative measurements` or `data points` that provide insights into the behavior and performance of a system.

### Types of Metrics
#### Gauges
Represent a `single numerical value` that can go up or down over time (e.g., CPU usage percentage).
#### Counters
 Monotonically increase and reset to zero when the process restarts (e.g., request count).
#### Histograms
 Capture the distribution of values (e.g., response time percentiles).