#! /bin/bash

PROJECT=$(basename $(pwd))

if [ -z "${SLIDES_DIR}" ]
then
    if [ -d "/vagrant/transfer" ]
    then
        SLIDES_DIR=/vagrant/transfer/mcpp17
    else
        SLIDES_DIR=./temp
    fi
fi

if [ ! -d "${SLIDES_DIR}" ]
then
    mkdir -p ${SLIDES_DIR}
fi

markdown-to-slides -i -s remark-template.css slides.md -o ${SLIDES_DIR}/slides.html -j script/script.js
cp -r fonts ${SLIDES_DIR}
cp -r images ${SLIDES_DIR}
cp -r script ${SLIDES_DIR}
#sed -i 's|https://gnab.github.io/remark/downloads|script|' ${SLIDES_DIR}/slides.html
sed -i 's|var slideshow = remark.create();||' ${SLIDES_DIR}/slides.html
sed -i "s|<title>.*</title>|<title>${PROJECT}</title>|" ${SLIDES_DIR}/slides.html
