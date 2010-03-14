#include <aubio.h>

int main(){
        /* allocate some memory */
        uint_t win_s      = 1024;                       /* window size */
        uint_t hop_s      = win_s/4;                    /* hop size */
        uint_t samplerate = 44100;                      /* samplerate */
        uint_t channels   = 1;                          /* number of channel */
        fvec_t * in       = new_fvec (hop_s, channels); /* input buffer */
        aubio_pitchfcomb_t * o  = new_aubio_pitchfcomb (
          win_s, hop_s, samplerate
          );
        uint_t i = 0;

        while (i < 1000) {
          aubio_pitchfcomb_detect(o,in);
          i++;
        };

        del_aubio_pitchfcomb(o);
        del_fvec(in);
        aubio_cleanup();

        return 0;
}
