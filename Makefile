CONTRACT=watchdoggiee

all: $(CONTRACT).abi $(CONTRACT).wasm

%.wasm: %.cpp
	eosiocpp $^

%.abi: %.cpp
	eosiocpp -o $@ $^
