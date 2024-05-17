# PicoScrewDLL
To build the python library, go to `newport_usb_wrap_pybind11` folder and run: 
```
pip install ./ --upgrade
```

Tested with `Python 3.11.5` and `Python 3.8.13`

For first time using, remeber to build `newport_usb_wrap_pybind11.vcxproj` first 

If the build shows error: 
```
LINK : fatal error LNK1181: cannot open input file 'newport_usb_wrap_pybind11.lib'
```
, try to upgrade the `pip` to be greater than `21.3`, since this is the minimum version of pip that supports `*.toml`.
Or can try to specify the absolute path of `newport_usb_wrap_pybind11.lib` in `setup.py`:
```
library_dirs = [r"..\x64\Release", r".\3rd_Party\Newport\Newport_USB_Driver\Lib"],
```
since the error comes from the confusion of using `"..\"` syntax in path definition