#include "TObject.h"
#include "TClonesArray.h"

#include "Particle.h"
#include "Event.h"

Event::Event()
{
	fEid = 0;
	fParticles = new TClonesArray("Particle",15);
	fNpa = fNneg = fNneu = fNpos = 0;
}

Event::Event(UInt_t eid)
{
	fEid = eid;
	fParticles = new TClonesArray("Particle",15);
	fNpa = fNneg = fNneu = fNpos = 0;
}

Event::~Event()
{
	Clear();
	delete fParticles;
}

Particle* Event::GetParticle(UInt_t index) const
{
	if((index < 0) || (index >= fNpa))
		return NULL;

	return ((Particle*) fParticles->At(index));
}

UInt_t Event::GetFirstParticle() const
{
	return (((Particle*)(fParticles->At(0)))->GetPid());
}

void Event::AddParticle(UInt_t pid, Int_t pdgpid, Short_t charge, Float_t px, Float_t py, Float_t pz, Float_t mass)
{
	new ((*fParticles) [fNpa]) Particle(pid, pdgpid, charge, px, py, pz, mass);
	fNpa++;
	
	if(charge != 0)
		if(charge < 0)
			fNneg++;
		else
			fNpos++;
	else
		fNneu++;
}

void Event::AddParticle(const Particle& particle)
{
	new ((*fParticles) [fNpa]) Particle(particle);
	fNpa++;

	if(particle.GetCharge() != 0)
		if(particle.GetCharge() < 0)
			fNneg++;
		else
			fNpos++;
	else
		fNneu++;
}

void Event::Clear()
{
	fParticles->Clear();
	fNpa = fNneu = fNneg = fNpos = 0;
}

ClassImp(Event);
