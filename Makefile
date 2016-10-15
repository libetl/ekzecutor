.PHONY: clean All

All:
	@echo "----------Building project:[ ekzecutor - Debug ]----------"
	@"$(MAKE)" -f  "ekzecutor.mk"
clean:
	@echo "----------Cleaning project:[ ekzecutor - Debug ]----------"
	@"$(MAKE)" -f  "ekzecutor.mk" clean
