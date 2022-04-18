﻿# sewerat
## a WIP remote access tool

  - [Details](#details)
  - [Features](#features)
  - [Further details](#further-details)
  - [How to build](#how-to-build)
  - [License](#licence)
  - [Disclaimer](#disclaimer)
  - [Authors](#authors)

## Details

 - Client written in C++
 - Builder written in C#
 - TCP C2 server (not yet implemented)


## Features

| Task                                                  | Assigned to | Done?  |
|-------------------------------------------------------|-------------|--------|
| Reverse Shell                                         | N/A         | :x:    |
| Privilege Escalation                                  | N/A         | :x:    |
| Screenshots                                           | N/A         | :x:    |
| Process Management (listing, killing etc.)            | N/A         | :x:    |
| Keylogger                                             | @nullndvoid | :star: |
| RNC/RDP/Remote Desktop function                       | N/A         | :x:    |
| System Info                                           | N/A         | :star: |
| Browser Passwords, History                            | N/A         | :x:    |
| Webcam Stream                                         | N/A         | :x:    |
| Changing the wallpaper                                | N/A         | :x:    |
| Geolocation                                           | N/A         | :x:    |
| Pseudocode/Documentation                              | @Pradhu007  | :star: |
| Discord Tokens (less important, soon to be encrypted) | N/A         | :x:    |

Key: :star: = started | :x: = not started duh | ✔️ = completed

## Further details

See [attack-stages.md](./plan/attack-stages.md) for further implementation details and the attack steps.


## How to build

To build the software at the moment, you will need:

* meson
* ninja
* msys2 (if on Windows)
* mingw (to build on Linux)
* clang

To build and run, either run the helper scripts in [util](./util/) or this:

```sh
meson build
ninja -C build
```

The output is in the build directory.

## License

I haven't decided yet, I suppose this _should_ be GPL 2.0 for ethical reasons, 
but I might just use MIT, so retards can go to jail.

## Disclaimer

Do not use this for any malicious purposes. Do not use this software to break any laws. 
The authors are not responsible for anything you choose to do with this software!

## Authors

* [@nullndvoid](https://github.com/nullndvoid)
* [@Pradhu007](https://github.com/pradhu007)

Feel free to contribute and add your name here!