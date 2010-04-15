/* test sample for phase vocoder 
 *
 * this program should start correctly using JACK_START_SERVER=true and
 * reconstruct each audio input frame perfectly on the corresponding input with
 * a delay equal to the window size, hop_s.
 */

#include <aubio.h>

int main(){
	int i;
        uint_t win_s    = 1024; /* window size                       */
        uint_t hop_s    = 256;  /* hop size                          */
        uint_t channels = 4;  /* number of channels                */
        /* allocate some memory */
        fvec_t * in       = new_fvec (hop_s, channels); /* input buffer       */
        cvec_t * fftgrain = new_cvec (win_s, channels); /* fft norm and phase */
        cvec_t * cstead   = new_cvec (win_s, channels); /* fft norm and phase */
        cvec_t * ctrans   = new_cvec (win_s, channels); /* fft norm and phase */
        fvec_t * stead    = new_fvec (hop_s, channels); /* output buffer      */
        fvec_t * trans    = new_fvec (hop_s, channels); /* output buffer      */
        /* allocate fft and other memory space */
        aubio_pvoc_t * pv = new_aubio_pvoc (win_s,hop_s,channels);
        aubio_pvoc_t * pvt = new_aubio_pvoc(win_s,hop_s,channels);
        aubio_pvoc_t * pvs = new_aubio_pvoc(win_s,hop_s,channels);

	aubio_tss_t *  tss = new_aubio_tss(0.01,3.,4.,win_s,hop_s,channels);
        /* fill input with some data */
        printf("initialised\n");
        /* execute stft */
	for (i = 0; i < 10; i++) {
		aubio_pvoc_do (pv,in,fftgrain);
		aubio_tss_do  (tss,fftgrain,ctrans,cstead);
		aubio_pvoc_rdo(pvt,cstead,stead);
		aubio_pvoc_rdo(pvs,ctrans,trans);
	}
        del_aubio_pvoc(pv);
        del_fvec(in);
        del_cvec(fftgrain);
        del_cvec(cstead);
        del_cvec(ctrans);
        del_fvec(stead);
        del_fvec(trans);
        aubio_cleanup();
        printf("memory freed\n");
        return 0;
}
