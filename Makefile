CXX=g++
CXXFLAGS=-std=c++17 -O3 -g -Wall -Wextra -pedantic

src_dir        = src
infra_src_dir   = $(src_dir)/infra
main_src_dir   = $(src_dir)/main
test_src_dir   = $(src_dir)/test
build_dir      = out
infra_build_dir = $(build_dir)/infra
main_build_dir = $(build_dir)/main
test_build_dir = $(build_dir)/test

dependencies   := .dependencies
dep_flags       = -MT $@ -MMD -MP -MF $(dependencies)/$*.d

target = rtc

infra_objects := $(patsubst $(infra_src_dir)/%.cc,$(infra_build_dir)/%.o, $(wildcard $(infra_src_dir)/*.cc))
test_objects := $(patsubst $(test_src_dir)/%.cc,$(test_build_dir)/%.o, $(wildcard $(test_src_dir)/*.cc))

test_files   := $(wildcard $(test_src_dir)/*.h)

includes = $(infra_src_dir)

.PHONY: all test clean
all: test_suite cannon

$(infra_build_dir)/%.o: $(infra_src_dir)/%.cc
$(infra_build_dir)/%.o: $(infra_src_dir)/%.cc $(dependencies)/%.d | $(dependencies)
	@echo "compiling $<"
	@mkdir -p $(infra_build_dir)
	@$(CXX) $(dep_flags) $(CXXFLAGS) -c $< -o $@

$(main_build_dir)/%.o: $(main_src_dir)/%.cc
$(main_build_dir)/%.o: $(main_src_dir)/%.cc $(dependencies)/%.d | $(dependencies)
	@echo "compiling $<"
	@mkdir -p $(main_build_dir)
	@$(CXX) $(dep_flags) $(CXXFLAGS) -I $(includes) -c $< -o $@

$(dependencies): ; @mkdir -p $@

$(test_build_dir)/%.o: $(test_src_dir)/%.cc $(dependencies)/%.d | $(dependencies)
	@echo "compiling $<"
	@mkdir -p $(test_build_dir)
	@$(CXX) $(dep_flags) $(CXXFLAGS) -I $(includes) -c $< -o $@

test_suite: $(infra_objects) $(test_objects) 
	@echo "linking $@"
	@$(CXX) $(CXXFLAGS) -o test_suite $(infra_objects) $(test_objects) -lgtest

cannon: $(main_build_dir)/cannon.o $(infra_objects)
	@echo "linking $@"
	@$(CXX) $(CXXFLAGS) -o cannon $< $(infra_objects)

test: test_suite
	@./test_suite

clean:
	@rm -f test_suite
	@rm -f cannon
	@rm -rf $(build_dir)
	@rm -rf $(dependencies)

infra_dep_files := $(patsubst $(infra_src_dir)/%.cc,$(dependencies)/%.d, $(wildcard $(infra_src_dir)/*.cc))
$(infra_dep_files):
main_dep_files := $(patsubst $(main_src_dir)/%.cc,$(dependencies)/%.d, $(wildcard $(main_src_dir)/*.cc))
$(main_dep_files):
test_dep_files := $(patsubst $(test_src_dir)/%.cc,$(dependencies)/%.d, $(wildcard $(test_src_dir)/*.cc))
$(test_dep_files):

include $(wildcard $(infra_dep_files))
include $(wildcard $(main_dep_files))
include $(wildcard $(test_dep_files))
