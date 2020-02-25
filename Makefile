CXX=g++
CXXFLAGS=-std=c++17 -O3 -g -Wall -Wextra -pedantic

src_dir        = src
prod_src_dir   = $(src_dir)/main
test_src_dir   = $(src_dir)/test
build_dir      = out
prod_build_dir = $(build_dir)/main
test_build_dir = $(build_dir)/test

target = rtc

prod_objects := $(patsubst $(prod_src_dir)/%.cc,$(prod_build_dir)/%.o, $(wildcard $(prod_src_dir)/*.cc))
test_objects := $(patsubst $(test_src_dir)/%.cc,$(test_build_dir)/%.o, $(wildcard $(test_src_dir)/*.cc))

includes = $(prod_src_dir)

.PHONY: all
all: $(prod_objects)

$(prod_build_dir)/%.o: $(prod_src_dir)/%.cc $(prod_src_dir)/%.h
	@mkdir -p $(prod_build_dir)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(test_build_dir)/%.o: $(test_src_dir)/%.cc
	@mkdir -p $(test_build_dir)
	$(CXX) $(CXXFLAGS) -I $(includes) -c $< -o $@ -lgtest

.PHONY: test
test: $(prod_objects) $(test_objects)
	$(CXX) $(CXXFLAGS) -o test_suite $(prod_objects) $(test_objects) -lgtest
	@./test_suite

.PHONY: clean
clean:
	rm -f test_suite
	rm -rf $(build_dir)
