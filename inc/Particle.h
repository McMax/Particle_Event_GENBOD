#ifndef PARTICLE_H
#define PARTICLE_H

#include "TObject.h"

class Particle : public TObject
{
	UInt_t fPid;		//Particle index
	Int_t	fPDGpid;
	Short_t fCharge;	//Particle absolute charge
	Float_t fPx;		//Particle momentum on X-axis
	Float_t fPy;		//Particle momentum on Y-axis
	Float_t fPz;		//Particle momentum on Z-axis
	Float_t fMass;

public:
	Particle();
	Particle(UInt_t, Int_t, Short_t, Float_t, Float_t, Float_t, Float_t);
	Particle(Particle&);
	Particle(Particle&, UInt_t);
	virtual ~Particle();

	inline UInt_t GetPid() const { return fPid;}
	inline Int_t GetPDGpid() const { return fPDGpid;}
	inline Short_t GetCharge() const { return fCharge;}
	inline Bool_t isPositive() const { return (fCharge <= 0 ? false : true);}
	inline Float_t GetPx() const { return fPx;}
	inline Float_t GetPy() const { return fPy;}
	inline Float_t GetPz() const { return fPz;}
	inline Float_t GetMass() const {return fMass;}
	
	inline void SetPid(UInt_t pid) { fPid = pid;}
	inline void SetPDGpid(Int_t pdgpid) { fPDGpid = pdgpid;}
	inline void SetCharge(Short_t charge) { fCharge = charge;}
	inline void SetPx(Float_t px) { fPx = px;}
	inline void SetPy(Float_t py) { fPy = py;}
	inline void SetPz(Float_t pz) { fPz = pz;}

	ClassDef(Particle,1);
};

#endif
