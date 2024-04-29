#include "NewportUSB.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>


namespace py = pybind11;

PYBIND11_MODULE(newport_usb_wrap_pybind11, m) {
	py::class_<NewportUSB> usb(m, "NewportUSB");
	usb.def(py::init<>())
		.def_readonly_static("m_knMaxBufferLength", &NewportUSB::m_knMaxBufferLength)
		.def("initSystem", &NewportUSB::initSystem, "void initSystem()")
		.def("uninitSystem", &NewportUSB::uninitSystem, "void uninitSystem()")
		.def("OpenDevices", static_cast<bool (NewportUSB::*)(int, bool)>(&NewportUSB::OpenDevices),
			"bool OpenDevices (int nProductID, bool bUsingDeviceKey)")
		.def("CloseDevices", &NewportUSB::CloseDevices, "void CloseDevices ()")
		.def("GetDeviceTable", &NewportUSB::GetDeviceTable, "std::map <std::string, int> GetDeviceTable ()")
		//.def("Read", static_cast<int (NewportUSB::*)(std::string, char*, int, unsigned long*)>(&NewportUSB::Read),
		//	"int Read (std::string strDeviceKey, char* lpBuffer, int nLength, unsigned long* lBytesRead)")
		//.def("Read", static_cast<int (NewportUSB::*)(std::string, std::string&)>(&NewportUSB::Read),
		//	"int Read(std::string strDeviceKey, std::string& readBuff)")
		.def("Read", static_cast<std::tuple<int,std::string> (NewportUSB::*)(std::string)>(&NewportUSB::Read),
			"std::tuple<int, std::string> Read(std::string strDeviceKey)")
		.def("Write", static_cast<int (NewportUSB::*)(std::string, std::string)>(&NewportUSB::Write), "int Write (std::string strDeviceKey, std::string strBuffer)")
		;


	py::class_<NewportUSB::DevInfo>(usb, "DevInfo")
		.def(py::init<>())
		.def_readwrite("nID", &NewportUSB::DevInfo::nID)
		.def_readwrite("strDescription", &NewportUSB::DevInfo::strDescription);

}





//struct Pet {
//    enum Kind {
//        Dog = 0,
//        Cat
//    };
//
//    struct Attributes {
//        float age = 0;
//    };
//
//    Pet(const std::string& name, Kind type) : name(name), type(type) { }
//
//    std::string name;
//    Kind type;
//    Attributes attr;
//};

//PYBIND11_MODULE(newport_usb_wrap_pybind11, m) {
//    //py::class_<NewportUSB>(m, "NewportUSB")
//    //    .def(py::init<void>())
//    //    .def("OpenDevices", static_cast<bool (NewportUSB::*)(int, bool)>(&NewportUSB::OpenDevices), 
//    //        "bool OpenDevices (int nProductID, bool bUsingDeviceKey)");
//
//    py::class_<Pet> pet(m, "Pet");
//
//    pet.def(py::init<const std::string&, Pet::Kind>())
//        .def_readwrite("name", &Pet::name)
//        .def_readwrite("type", &Pet::type)
//        .def_readwrite("attr", &Pet::attr);
//
//    py::enum_<Pet::Kind>(pet, "Kind")
//        .value("Dog", Pet::Kind::Dog)
//        .value("Cat", Pet::Kind::Cat)
//        .export_values();
//
//    py::class_<Pet::Attributes>(pet, "Attributes")
//        .def(py::init<>())
//        .def_readwrite("age", &Pet::Attributes::age);
//
//
//}
