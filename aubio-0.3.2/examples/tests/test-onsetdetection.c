
#include <aubio.h>

int main(){
        /* allocate some memory */
        uint_t win_s      = 1024;                       /* window size */
        uint_t channels   = 1;                          /* number of channel */
        cvec_t * in       = new_cvec (win_s, channels); /* input buffer */
        fvec_t * out      = new_fvec (1, channels);     /* input buffer */
  
        /* allocate fft and other memory space */
        aubio_onsetdetection_t * o = 
          new_aubio_onsetdetection(aubio_onset_energy, win_s, channels);
        aubio_onsetdetection(o,in,out);
        aubio_onsetdetection_energy(o,in,out);
        del_aubio_onsetdetection(o);

        o = new_aubio_onsetdetection(aubio_onset_specdiff, win_s, channels);
        aubio_onsetdetection(o,in,out);
        aubio_onsetdetection_specdiff(o,in,out);
        del_aubio_onsetdetection(o);

        o = new_aubio_onsetdetection(aubio_onset_hfc, win_s, channels);
        aubio_onsetdetection(o,in,out);
        aubio_onsetdetection_hfc(o,in,out);
        del_aubio_onsetdetection(o);

        o = new_aubio_onsetdetection(aubio_onset_complex, win_s, channels);
        aubio_onsetdetection(o,in,out);
        aubio_onsetdetection_complex(o,in,out);
        del_aubio_onsetdetection(o);

        o = new_aubio_onsetdetection(aubio_onset_phase, win_s, channels);
        aubio_onsetdetection(o,in,out);
        aubio_onsetdetection_phase(o,in,out);
        del_aubio_onsetdetection(o);

        o = new_aubio_onsetdetection(aubio_onset_kl, win_s, channels);
        aubio_onsetdetection(o,in,out);
        aubio_onsetdetection_kl(o,in,out);
        del_aubio_onsetdetection(o);

        o = new_aubio_onsetdetection(aubio_onset_mkl, win_s, channels);
        aubio_onsetdetection(o,in,out);
        aubio_onsetdetection_mkl(o,in,out);
        del_aubio_onsetdetection(o);

        del_cvec(in);
        del_fvec(out);
        aubio_cleanup();

        return 0;
}

