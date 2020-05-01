CXX=g++
CXXFLAGS=-std=c++17 -O3 -g -Wall -Wextra -pedantic

src_dir        = src
prod_src_dir   = $(src_dir)/main
test_src_dir   = $(src_dir)/test
build_dir      = out
prod_build_dir = $(build_dir)/main
test_build_dir = $(build_dir)/test

dependencies   := .dependencies
dep_flags       = -MT $@ -MMD -MP -MF $(dependencies)/$*.d

target = rtc

prod_objects := $(patsubst $(prod_src_dir)/%.cc,$(prod_build_dir)/%.o, $(wildcard $(prod_src_dir)/*.cc))
test_objects := $(patsubst $(test_src_dir)/%.cc,$(test_build_dir)/%.o, $(wildcard $(test_src_dir)/*.cc))

test_files   := $(wildcard $(test_src_dir)/*.h)

includes = $(prod_src_dir)

.PHONY: all test clean
all: test_suite

$(prod_build_dir)/%.o: $(prod_src_dir)/%.cc
$(prod_build_dir)/%.o: $(prod_src_dir)/%.cc $(dependencies)/%.d | $(dependencies)
	@echo "compiling $<"
	@mkdir -p $(prod_build_dir)
	@$(CXX) $(dep_flags) $(CXXFLAGS) -c $< -o $@

$(dependencies): ; @mkdir -p $@

$(test_build_dir)/%.o: $(test_src_dir)/%.cc $(dependencies)/%.d | $(dependencies)
	@echo "compiling $<"
	@mkdir -p $(test_build_dir)
	@$(CXX) $(dep_flags) $(CXXFLAGS) -I $(includes) -c $< -o $@

test_suite: $(prod_objects) $(test_objects) 
	@echo "linking $@"
	@$(CXX) $(CXXFLAGS) -o test_suite $(prod_objects) $(test_objects) -lgtest

test: test_suite
	@./test_suite

clean:
	@rm -f test_suite
	@rm -rf $(build_dir)
	@rm -rf $(dependencies)

prod_dep_files := $(patsubst $(prod_src_dir)/%.cc,$(dependencies)/%.d, $(wildcard $(prod_src_dir)/*.cc))
$(prod_dep_files):
test_dep_files := $(patsubst $(test_src_dir)/%.cc,$(dependencies)/%.d, $(wildcard $(test_src_dir)/*.cc))
$(test_dep_files):

include $(wildcard $(prod_dep_files))
include $(wildcard $(test_dep_files))
