build-stamp:
	sh $(srcdir)/install_cmakeconfig.sh --with-core=$(XENO_TARGET_CORE) --prefix="$(prefix)" \
	  --exec-prefix="$(exec_prefix)" --libdir="$(libdir)" --includedir="$(includedir)" . && \
	touch $@

xenomai-config.cmake xenomai-macros.cmake \
	xenomai-targets.cmake xenomai-targets-noconfig.cmake: build-stamp

cmakeconfigdir = $(libdir)/cmake/$(PACKAGE)
cmakeconfig_DATA = xenomai-config.cmake xenomai-macros.cmake xenomai-config-version.cmake \
	xenomai-targets.cmake xenomai-targets-noconfig.cmake

CLEANFILES = build-stamp xenomai-config.cmake xenomai-config-version.cmake xenomai-macros.cmake \
	xenomai-targets.cmake xenomai-targets-noconfig.cmake
