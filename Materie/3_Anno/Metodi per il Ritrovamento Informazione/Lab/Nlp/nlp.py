# https://colab.research.google.com/drive/1Dx-8mN7QOVk4HoGZeUD3iW_SQvA3JtbS?usp=sharing#scrollTo=cR-HyfqPoTil

import spacy

nlp = spacy.load('en_core_web_lg')
nlp.pipe_names

text = "Hello world!"
doc = nlp(text)

for token in doc:
    print(token.text)

print("".join([token.text_with_ws for token in doc]))

for token in doc:
    print(f"Token: {token.text}, Index: {token.idx}")

text = "On January 12th, I will be in the U.K."
doc = nlp(text)

for token in doc:
    print("{0}\t{1}\t{2}\t{3}\t{4}\t{5}\t{6}\t{7}".format(
        token.text,
        token.idx,
        token.lemma_,
        token.is_punct,
        token.is_space,
        token.shape_,
        token.pos_,
        token.tag_
    ))