CXX=clang++
CXXFLAGS=-Wall -Wextra -g -O3 -Wfatal-errors -Werror -std=c++0x

SWIG_CXX=g++
SWIG_CXXFLAGS=-O2 -std=c++0x
PYTHON_INCLUDE=$(shell python3.5-config --cflags)
PYTHON_LIBS=$(shell python3.5-config --ldflags)

MODULES=io Word LemmaExtractor LabelExtractor Sentence ParamTable \
Data TrellisColumn Trellis Trainer PerceptronTrainer SGDTrainer \
TrellisCell Tagger TaggerOptions SuffixLabelMap process_aux

TESTS=$(MODULES:%=TEST_%)
OBJS=$(MODULES:%=%.o)
SRCS=$(MODULES:%=%.cc)
PROGS=finnpos-train finnpos-label finnpos-eval finnpos-print-params finnpos-filter-params finnpos-lemmatize

all:$(PROGS)

install:all
	cp $(PROGS) ../../bin

uninstall:
	rm -f $(PROGS:%=../../bin/%)

clean:
	rm -f $(OBJS) $(TESTS) $(PROGS) finnpos.o _finnpos.so finnpos_wrap.cxx finnpos_wrap.o

doc-clean:
	rm -Rf html latex

doc: html

html:
	doxygen Doxyfile

test:$(TESTS)
	for t in $(TESTS); \
	do                 \
	echo $$t && ./$$t || echo "FAILED"; \
	done

TEST_%:$(OBJS) %.cc
	$(CXX) $(CXXFLAGS) -DTEST_$*_cc -o $@ $^

finnpos-train:finnpos-train.cc $(OBJS)
finnpos-label:finnpos-label.cc $(OBJS)
finnpos-lemmatize:finnpos-lemmatize.cc $(OBJS)
finnpos-eval:finnpos-eval.cc $(OBJS)
finnpos-print-params:finnpos-print-params.cc $(OBJS)
finnpos-filter-params:finnpos-filter-params.cc $(OBJS)

swig: finnpos_obj swig_obj pic_objs
	$(SWIG_CXX) $(SWIG_CXXFLAGS) -shared finnpos.o $(OBJS) finnpos_wrap.o -o _finnpos.so

finnpos_obj: finnpos.cc finnpos.h
	$(SWIG_CXX) $(SWIG_CXXFLAGS) -fPIC -c finnpos.cc

pic_objs: $(SRCS)
	$(SWIG_CXX) $(SWIG_CXXFLAGS) -fPIC -c $(SRCS)

swig_obj: swig_wrap
	$(SWIG_CXX) $(SWIG_CXXFLAGS) $(PYTHON_INCLUDE) $(PYTHON_LIBS) -fPIC -c finnpos_wrap.cxx

swig_wrap: finnpos.i
	swig -c++ -python finnpos.i
