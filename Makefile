#This makefile makes all the main book code with CppUTest test harness

#Set this to @ to keep the makefile quiet
SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = BookCode_CppUTest

#--- Inputs ----#
CPP_PLATFORM = Gcc
PROJECT_HOME_DIR = .

SRC_DIRS = \
	src/HomeAutomation \
	src/util\
	mocks\

TEST_SRC_DIRS = \
	.\
	cpputest/HomeAutomation\
	cpputest/util\
	cpputest\
	mocks\

INCLUDE_DIRS =\
	.\
	$(CPPUTEST_HOME)/include\
	include/HomeAutomation\
	include/util\

MOCKS_SRC_DIRS = \
	mocks\
	
CPPUTEST_WARNINGFLAGS = -Wall -Wswitch-default -Werror 
#CPPUTEST_CFLAGS = -std=c89 
CPPUTEST_CFLAGS += -Wall -Wstrict-prototypes -pedantic -std=c99
LD_LIBRARIES = -lpthread
	
  
ifeq ($(CPPUTEST_HOME),)
$(info CPPUTEST_HOME not set! See README.txt)
else  
include $(CPPUTEST_HOME)/build/MakefileWorker.mk
endif
