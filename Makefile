CONTRACT=watchdoggiee

all: $(CONTRACT).abi $(CONTRACT).wast

%.wast: %.cpp
	eosiocpp -o $@ $^

%.abi: %.cpp
	eosiocpp -g $@ $^

clean:
	rm -f $(CONTRACT).abi $(CONTRACT).wast $(CONTRACT).wasm
