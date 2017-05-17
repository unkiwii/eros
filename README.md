**_This is a work in progress_**

# eros

is a statically typed, general-purpose programming language. **eros** is being developed right now and must:
* Be easy to read and write
* Provide a fast and nice write-compile-run-debug cycle
* Be able to produce native code in any machine
* Have a small footprint (no runtime environment or virtual machine involved)

## Building

### *nix
It depends on ```libedit``` to be installed:

```
apt-get install libedit   # on debian
# TODO: add more distros here
```

To build just run:
```
make
```

### Windows

Just run:
```
nmake
```

The binary will be located at ```bin/eros```

## Testing

### *nix
```
make test
```

### Windows
```
nmake test
```
