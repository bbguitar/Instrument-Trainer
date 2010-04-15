/* test sample for phase vocoder */

#include <aubio.h>

int main(){
        uint_t win_s    = 1024; /* window size                       */
        uint_t hop_s    = 256;  /* hop size                          */
        uint_t channels = 4;  /* number of channels                */
        /* allocate some memory */
        fvec_t * in       = new_fvec (hop_s, channels); /* input buffer       */
        cvec_t * fftgrain = new_cvec (win_s, channels); /* fft norm and phase */
        fvec_t * out      = new_fvec (hop_s, channels); /* output buffer      */
        /* allocate fft and other memory space */
        aubio_pvoc_t * pv = new_aubio_pvoc(win_s,hop_s,channels);
        /* fill input with some data */
        printf("initialised\n");
        /* execute stft */
        aubio_pvoc_do (pv,in,fftgrain);
        printf("computed forward\n");
        /* execute inverse fourier transform */
        aubio_pvoc_rdo(pv,fftgrain,out);
        printf("computed backard\n");
        del_aubio_pvoc(pv);
        del_fvec(in);
        del_cvec(fftgrain);
        del_fvec(out);
        aubio_cleanup();
        printf("memory freed\n");
        return 0;
}
