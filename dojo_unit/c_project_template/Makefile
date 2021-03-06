################################################################################
#      DO NOT MODIFY THIS FILE UNLESS YOU ARE SURE OF WHAT YOU ARE DOING       #
################################################################################
all: run_tests

# All of the sources participating in the build are defined here
-include objects.mk
-include sources.mk
-include tests/subdir.mk
-include src/subdir.mk
-include $(OS_NAME).mk

run: $(BIN_DIR) $(PROJECT)
	@echo 'Running project executable'
	@echo ' '
	./$(BIN_DIR)/$(PROJECT)

run_tests: $(BIN_DIR) $(PROJECT)_tests
	@echo 'Running project tests executable'
	@echo ' '
	clear && ./$(BIN_DIR)/$(PROJECT)_tests $(ARGS)

# Tool invocations
$(PROJECT): $(BIN_DIR) $(CODE_OBJS)
	@echo 'Building target: $@'
	$(CC) $(LFLAGS) -o $(BIN_DIR)/$@ $(CODE_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

$(PROJECT)_tests: $(BIN_DIR) $(CODE_OBJS) $(TESTS_OBJS) $(LIB_DIR)/$(TESTS_LIB)
	@echo 'Building target: $@ with $(TESTS_LIB)'
	$(CC) $(LFLAGS) -o $(BIN_DIR)/$@ $(CODE_OBJS) $(TESTS_OBJS) $(LIBS) $(LIB_DIR)/$(TESTS_LIB)
	@echo 'Finished building target: $@'
	@echo ' '
	
$(TESTS_DIR)/$(PROJECT)_tests_main.c: $(TESTS_DIR)/$(PROJECT)_tests.h
	@echo 'Generating file: $@'
	cd $(TESTS_DIR) && ../$(SCRIPT_DIR)/generate_main_tests $(PROJECT)_tests
	@echo ' '

$(BIN_DIR):
	@echo 'Generating $@ folder'
	mkdir -p $@
	@echo ' '
	
$(LIB_DIR):
	@echo 'Generating $@ folder'
	mkdir -p $@
	@echo ' '

# Other Targets
clean:
	@echo 'Cleaning up project'
	-$(RM) $(CODE_OBJS) $(TESTS_OBJS) $(EXECUTABLES) $(TESTS_DIR)/$(PROJECT)_tests_main.c $(PROJECT) $(PROJECT)_tests $(BIN_DIR) */.DS_Store
	@echo ' '

.PHONY: all clean
.SECONDARY:

zip: clean ../$(PROJECT) $(BIN_DIR)
	@echo 'Generating $@ file for $(PROJECT)'
	cd .. && zip -r $(PROJECT)/$(BIN_DIR)/$(PROJECT).zip $(PROJECT) -x $(PROJECT)/$(LIB_DIR)/$(TESTS_LIB)
	@echo ' '

tar: clean ../$(PROJECT) $(BIN_DIR)
	@echo 'Generating $@ file for $(PROJECT)'
	cd .. && tar -cf $(PROJECT)/$(BIN_DIR)/$(PROJECT).tar $(PROJECT) -X $(PROJECT)/$(LIB_DIR)/$(TESTS_LIB)
	@echo ' '
	
targz: tar
	@echo 'Generating $@ file for $(PROJECT)'
	gzip $(BIN_DIR)/$(PROJECT).tar
	@echo ' '
