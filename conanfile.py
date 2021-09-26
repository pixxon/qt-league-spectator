from conans import ConanFile, CMake

class Test(ConanFile):
	name = "Test"
	version = "0.0.0"
	description = ""
	settings = "os", "compiler", "build_type", "arch"
	generators = "cmake", "cmake_find_package_multi"
	build_requires = "cmake/3.20.4"
	requires = "qt/6.1.3"
	default_options = {
		"qt:qttools": True,
		"qt:qtactiveqt" : True,
		"qt:qtdeclarative" : True,
		"qt:qtsvg": True,
		"qt:qtquickcontrols2": True,
		"qt:qtimageformats": True,
		"qt:shared": True
	}

	def _configure_cmake(self):
		cmake = CMake(self)
		cmake.configure(source_folder="src")
		return cmake

	def build(self):
		cmake = self._configure_cmake()
		cmake.build()

	def package(self):
		cmake = self._configure_cmake()
		cmake.install()
