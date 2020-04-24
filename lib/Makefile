TARGETS := all clean
LIBRARIES := $(wildcard */.)

$(TARGETS): $(LIBRARIES)
$(LIBRARIES):
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: all clean $(LIBRARIES)

# https://stackoverflow.com/questions/17834582/run-make-in-each-subdirectory