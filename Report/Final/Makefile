TGT=sig-alternate
DEPS=   sigproc.bib \
        abstract.tex \
        introduction.tex \
        motiv.tex \
        related.tex \
        language.tex \
        runtime.tex \
        related.tex \
        evaluation.tex \
        Figs/fig_motiv_3.tex \
        Figs/fig_motiv_4.tex \
        Figs/fig_motiv_5.tex \
        Figs/fig_language_1.tex \

LATEX=pslatex
BIBTEX=bibtex

all: $(TGT)
pdf: $(TGT).pdf

$(TGT): $(TGT).pdf

$(TGT).pdf: $(TGT).ps
	ps2pdf $(TGT).ps $(TGT).pdf

$(TGT).ps: $(TGT).dvi
	dvips -o $(TGT).ps $(TGT)

$(TGT).dvi: $(TGT).tex $(DEPS)
	$(LATEX) $(TGT) && $(BIBTEX) $(TGT) && $(LATEX) $(TGT)
#	$(BIBTEX) $(TGT)
	$(LATEX) $(TGT) && $(LATEX) $(TGT)

.PHONY: clean clobber fresh
clean: 
	-$(RM) -f $(TGT).dvi $(TGT).aux $(TGT).log
	-$(RM) -f $(TGT).toc $(TGT).idx $(TGT).bbl
	-$(RM) -f $(TGT).toc $(TGT).ind $(TGT).blg 
	-$(RM) -f $(TGT).ps $(TGT).ind 
	-$(RM) -f missfont.log *~

clobber: clean
	-$(RM) -f $(TGT).ps $(TGT).pdf

fresh: clobber all
