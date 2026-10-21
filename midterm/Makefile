CC = clang
CFLAGS = -Wall -Wextra -O2 -std=c99
MODULES = basics arrays pointers strings
BUILD_DIR = build

.PHONY: all clean $(addprefix run-,$(MODULES))

all: $(addprefix $(BUILD_DIR)/,$(MODULES))

$(BUILD_DIR):
	mkdir -p $@

define MODULE_template
$(BUILD_DIR)/$(1): $(1)/$(1).c | $(BUILD_DIR)
	$$(CC) $$(CFLAGS) -I$(1) -o $$@ $$<
endef

$(foreach module,$(MODULES),$(eval $(call MODULE_template,$(module))))

define RUN_template
run-$(1): $(BUILD_DIR)/$(1)
	./$$<
endef

$(foreach module,$(MODULES),$(eval $(call RUN_template,$(module))))

clean:
	rm -rf $(BUILD_DIR)
