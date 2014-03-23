include param.mk
OBJS=main.o

all : $(PROG)

$(PROG) : $(OBJS) $(SPTM)
	$(CC) $(CSSFLAGS)    -o $@ $^ $(LDFLAGS)

%.o : %.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

clean :
	@touch $(PROG) $(OBJS)
	@rm    $(PROG) $(OBJS)

rec : clean all

.PHONY: all prog clean rec


