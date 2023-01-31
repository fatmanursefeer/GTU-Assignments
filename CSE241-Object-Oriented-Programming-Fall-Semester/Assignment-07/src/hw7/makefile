JFLAGS = -g
JC = javac
JVM = java
MAIN = DayofYearSetMain
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
	DayofYearSetMain.java \
	scr/DayofYearSet.java 
	
default: classes

classes: $(CLASSES:.java=.class)

run: classes
	$(JVM) $(MAIN)
	
clean:
	$(RM) *.class
