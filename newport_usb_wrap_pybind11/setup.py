from setuptools import setup, Extension
import pybind11
from pybind11.setup_helpers import Pybind11Extension, build_ext

__version__ = "0.0.1"

# cpp_args = ['-std=c++17', '-stdlib=libc++', '-mmacosx-version-min=10.7']

ext_modules = [
    Pybind11Extension(
        name = "newport_usb_wrap_pybind11",
        sources = ["module.cpp", "NewportUSB.cpp"],
        include_dirs = [r".\3rd_Party\PyBind", r".\3rd_Party\Newport\Newport_USB_Driver\Include"],
        library_dirs = [r"..\x64\Release", r".\3rd_Party\Newport\Newport_USB_Driver\Lib"],
        libraries = ["usbdll", "newport_usb_wrap_pybind11"],
        language='c++',
        # extra_compile_args = cpp_args,
        # Example: passing in the version to the compiled code
        define_macros=[("VERSION_INFO", __version__)],
    ),
]


setup(
    name="newport_usb_wrap_pybind11",
    version=__version__,
    # author="",
    # author_email="",
    # url="",
    description="wrap newport usb from cpp to python using pybind11",
    long_description="",
    ext_modules=ext_modules,
    extras_require={"test": "pytest"},
    # Currently, build_ext only provides an optional "highest supported C++
    # level" feature, but in the future it may provide more features.
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
    python_requires=">=3.7",
)