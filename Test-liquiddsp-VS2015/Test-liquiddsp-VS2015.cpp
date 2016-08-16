// Test-liquiddsp-VS2015.cpp : main project file.

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "include\liquid.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	// options
	unsigned int nfft = 2401;    // FFT size
	unsigned int n = 3456;    // input buffer size
	float        beta = 10.0f;   // Kaiser-Bessel window parameter
	unsigned int wlen = nfft / 2;   // spgramcf window size

									// create spectral periodogram
	spgramcf q = spgramcf_create_kaiser(nfft, wlen, beta);

	// allocated memory arrays
	liquid_float_complex * x = (liquid_float_complex*) malloc(n * sizeof(liquid_float_complex));
	float         * psd = (float        *)malloc(n * sizeof(float));

	// ... initialize input ...

	// execute spectral estimation (repeat as necessary)
	spgramcf_accumulate_psd(q, x, n);

	// compute power spectral density output (repeat as necessary)
	spgramcf_write_accumulation(q, psd);

	// destroy FFT plan and free memory arrays
	spgramcf_destroy(q);
	free(x);
	free(psd);
    Console::WriteLine(L"Hello World");
    return 0;
}
