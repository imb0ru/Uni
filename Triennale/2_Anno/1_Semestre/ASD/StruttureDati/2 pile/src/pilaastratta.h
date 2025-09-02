#ifndef _PILAASTRATTA_H
#define _PILAASTRATTA_H

template <class T, class P>
class pilaAstratta {
public:
    typedef T tipoelem;
    typedef P posizione;

    virtual void creaPila() = 0;
    virtual bool pilaVuota() const = 0;
    virtual tipoelem leggiPila() const = 0;
    virtual void fuoriPila() = 0;
    virtual void inPila(tipoelem) = 0;
};

#endif // _PILAASTRATTA_H
