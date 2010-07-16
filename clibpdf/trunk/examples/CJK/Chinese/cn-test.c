/* cn-test.c -- test program for Chinese language support.
 * Copyright (C) 1999 FastIO Systems, All Rights Reserved.
 * For conditions of use, license, and distribution, see LICENSE.pdf
 * included in the distribution or http://www.fastio.com/LICENSE.pdf

This example file "cn-test.c" includes text from TeX documentation
released under GNU Public License as acknowledged below.  Although,
we do not believe that doing this places cn-test.c into GPL'ed
software, if that must be the case, then this file, "cn-test.c",
must be GPL'ed, so be it.
------------------------------------------------------------------------------------
1999-09-27 [io] Chinese version

cc -Wall -o cn-test -I/usr/local/include cn-test.c -lcpdfpm

The Chinese text data and the English original are from:
ftp://ftp.tex.ac.uk/tex-archive/language/chinese/CJK/4_2.0/examples/

*/

#include <stdio.h>
#include <stdlib.h>
#include <cpdflib.h>

/* EUC-Big 5 : Traditional Chinse (Taiwan) */
char *euc_b5_text[] = {
"���`�ݰݵ���~(FAQ list)~�O�q�@�Ǹg�`�Q�ݨ쪺���D�Ψ�A����",
"�����A�H��K���Φ��K�n�ӥX���C��W�@�����P���O�A��s�Ƶ��c�w�������ܡC",
"�����s���c���Ӹ`�A�i�Ѧҡu�p��\\Ū���ݵ����ΤF�Ѩ�s�Ƶ��c�v��",
"�����������C",
NULL
};

/* EUC-GB : Simplified Chinese (PR China) */
char *euc_gb_text[] = {
"�������ʴ�~(FAQ list)~�Ǵ�һЩ�������ʵ������⼰���ʵ��Ľ�",
"���У��Է������ʽժҪ�����ġ�����һ�治ͬ���ǣ�����Žṹ�ѳ��׸ı䡣",
"�й��½ṹ��ϸ�ڣ��ɲο�������Ķ����ʴ𼯼��˽�����Žṹ����",
"���е�˵����",
NULL
};

/* English */
char *english_text[] = {
"This FAQ list was made to summarize some frequently asked",
"questions and their answers in a convenient form.  The structure of",
"this FAQ list has drastically changed since the last version.",
"For details of the new structure, see the entry of `How to",
"read this FAQ and its structure'.",
"",
"The Chinese text data and the English original are from:",
"ftp://ftp.tex.ac.uk/tex-archive/language/chinese/CJK/4_2.0/examples/",
NULL
};

int main(int argc, char *argv[])
{
int i;
CPDFdoc *pdf;
float fontsize = 12.0;
float x = 1.0;
float y = 10.0;
int alignmode = TEXTPOS_LL;
float ybump = 0.25;

    /* == Initialization == */
    pdf = cpdf_open(0, NULL);
    cpdf_enableCompression(pdf, YES);		/* use Flate/Zlib compression */
    cpdf_init(pdf);
    cpdf_pageInit(pdf, 1, PORTRAIT, LETTER, LETTER);		/* page orientation */

    /* Traditional Chinese Big-5 encoding */
    cpdf_beginText(pdf, 0);
    cpdf_setFont(pdf, "MHei-Medium", "ETen-B5-H", fontsize);	/* Gothic type font */
    for(i = 0; euc_b5_text[i] != NULL; i++) {
	cpdf_textAligned(pdf, x, y, 0.0, alignmode, euc_b5_text[i]);
	y -= ybump;
    }
    cpdf_endText(pdf);

    y -= ybump;
    cpdf_beginText(pdf, 0);
    cpdf_setFont(pdf, "MHei-Medium,Bold", "ETen-B5-H", fontsize);	/* Gothic Bold type font */
    for(i = 0; euc_b5_text[i] != NULL; i++) {
	cpdf_textAligned(pdf, x, y, 0.0, alignmode, euc_b5_text[i]);
	y -= ybump;
    }
    cpdf_endText(pdf);

    /* Traditional Chinese Big-5 encoding */
    y -= ybump;
    cpdf_beginText(pdf, 0);
    cpdf_setFont(pdf, "MSung-Light", "ETen-B5-H", fontsize);	/* Light type font */
    for(i = 0; euc_b5_text[i] != NULL; i++) {
	cpdf_textAligned(pdf, x, y, 0.0, alignmode, euc_b5_text[i]);
	y -= ybump;
    }
    cpdf_endText(pdf);

    y -= ybump;
    cpdf_beginText(pdf, 0);
    cpdf_setFont(pdf, "MSung-Light,Bold", "ETen-B5-H", fontsize);	/* Light Bold type font */
    for(i = 0; euc_b5_text[i] != NULL; i++) {
	cpdf_textAligned(pdf, x, y, 0.0, alignmode, euc_b5_text[i]);
	y -= ybump;
    }
    cpdf_endText(pdf);

    /* Simplified Chinese: GB encoding */
    y -= ybump;
    cpdf_beginText(pdf, 0);
    cpdf_setFont(pdf, "STSong-Light", "GBK-EUC-H", fontsize);	/* STSong-Light font */
    for(i = 0; euc_gb_text[i] != NULL; i++) {
	cpdf_textAligned(pdf, x, y, 0.0, alignmode, euc_gb_text[i]);
	y -= ybump;
    }
    cpdf_endText(pdf);
    y -= ybump;
    cpdf_beginText(pdf, 0);
    cpdf_setFont(pdf, "STSong-Light,BoldItalic", "GBK-EUC-H", fontsize);	/* STSong-Light BoldItalic font */
    for(i = 0; euc_gb_text[i] != NULL; i++) {
	cpdf_textAligned(pdf, x, y, 0.0, alignmode, euc_gb_text[i]);
	y -= ybump;
    }
    cpdf_endText(pdf);

    y -= ybump;
    cpdf_beginText(pdf, 0);
    cpdf_setFont(pdf, "Helvetica", "MacRomanEncoding", fontsize);
    for(i = 0; english_text[i] != NULL; i++) {
	cpdf_textAligned(pdf, x, y, 0.0, alignmode, english_text[i]);
	y -= ybump;
    }
    cpdf_endText(pdf);

    cpdf_finalizeAll(pdf);			/* PDF file/memstream is actually written here */
    cpdf_savePDFmemoryStreamToFile(pdf, "cn-test.pdf");
    cpdf_launchPreview(pdf);		/* launch Acrobat/PDF viewer on the output file */

    /* == Clean up == */
    cpdf_close(pdf);			/* shut down */
    return 0;

}


