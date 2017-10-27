ASSETS := $(addsuffix .ascii.h, $(basename $(addprefix gen/, $(notdir $(wildcard assets/*.png)))))

all: gen $(ASSETS) lol.cpp
	$(CXX) lol.cpp -o lol

gen:
	mkdir -p gen

gen/%.ascii: assets/%.png
	ponysay -f $< -o > $@

gen/%.ascii.h: gen/%.ascii
	xxd -i $< > $@

clean:
	rm -rf lol gen

.PHONY: gen
