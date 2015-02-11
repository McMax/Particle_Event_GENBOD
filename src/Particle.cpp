#include "TObject.h"
#include "Particle.h"

Particle::Particle()
{
	fPid = 0;
	fPDGpid = 0;
	fCharge = 0;
	fPx = fPy = fPz = fMass = 0.;
}

Particle::Particle(UInt_t pid, Int_t pdgpid, Short_t charge, 
			Float_t px, Float_t py, Float_t pz,
			Float_t mass)
			
{
	fPid = pid;
	fPDGpid = pdgpid;
	fCharge = charge;

	fPx = px;
	fPy = py;
	fPz = pz;

	fMass = mass;
}

Particle::~Particle()
{

}

ClassImp(Particle);
