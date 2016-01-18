PDF =   bericht.pdf
SRC =   bericht.tex
EPS =	Flussdiagramm_erster_teil.eps\
	Flussdiagramm_zweiter_teil.eps

all: $(PDF)

$(PDF): $(SRC) $(EPS)
	rubber -d $(SRC)

%.eps: images/%.dia
	dia-normal -e $@ -t eps $<

clean:
	rm -f $(patsubst %,$(basename $(SRC)).%,aux lof log lot out toc) $(EPS) $(patsubst %.eps,%-eps-converted-to.pdf,$(EPS))

.PHONY: all clean
