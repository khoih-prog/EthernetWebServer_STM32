---
name: Bug report
about: Create a report to help us improve
title: ''
labels: ''
assignees: ''

---

### Describe the bug

A clear and concise description of what the bug is.

### Steps to Reproduce

Steps to reproduce the behavior. Including the [MRE](https://stackoverflow.com/help/minimal-reproducible-example) sketches

### Expected behavior

A clear and concise description of what you expected to happen.

### Actual behavior

A clear and concise description of what you expected to happen.

### Debug and AT-command log (if applicable)

A clear and concise description of what you expected to happen.

### Screenshots

If applicable, add screenshots to help explain your problem.

### Information

Please ensure to specify the following:

* Arduino IDE version (e.g. 1.8.19) or Platform.io version
* Board Core Version (e.g. STM32F7 Nucleo-144 NUCLEO_F767ZI, STM32 core v2.3.0, etc.)
* Contextual information (e.g. what you were trying to achieve)
* Simplest possible steps to reproduce
* Anything that might be relevant in your opinion, such as:
  * Operating system (Windows, Ubuntu, etc.) and the output of `uname -a`
  * Network configuration


### Example

```
Arduino IDE version: 1.8.19
STM32F7 Nucleo-144 NUCLEO_F767ZI, STM32 core v2.3.0
OS: Ubuntu 20.04 LTS
Linux xy-Inspiron-3593 5.15.0-53-generic #59~20.04.1-Ubuntu SMP Thu Oct 20 15:10:22 UTC 2022 x86_64 x86_64 x86_64 GNU/Linux

Context:
I encountered a crash while using this library

Steps to reproduce:
1. ...
2. ...
3. ...
4. ...
```

---

### Sending Feature Requests

Feel free to post feature requests. It's helpful if you can explain exactly why the feature would be useful.

There are usually some outstanding feature requests in the [existing issues list](https://github.com/khoih-prog/EthernetWebServer_STM32/issues?q=is%3Aopen+is%3Aissue+label%3Aenhancement), feel free to add comments to them.

---

### Sending Pull Requests

Pull Requests with changes and fixes are also welcome!

Please use the `astyle` to reformat the updated library code as follows (demo for Ubuntu Linux)

1. Change directory to the library GitHub

```
xy@xy-Inspiron-3593:~$ cd Arduino/xy/EthernetWebServer_STM32_GitHub/
xy@xy-Inspiron-3593:~/Arduino/xy/EthernetWebServer_STM32_GitHub$
```

2. Issue astyle command

```
xy@xy-Inspiron-3593:~/Arduino/xy/EthernetWebServer_STM32_GitHub$ bash utils/restyle.sh
```


