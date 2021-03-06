
#pragma once

#include "Packable.h"
#include "GameEnums.h"
#include "ObjCache.h"

class SpellComponentBase : public PackObj
{
public:
	SpellComponentBase();
	virtual ~SpellComponentBase();

	DECLARE_PACKABLE()

	std::string _name;
	SpellComponentCategory _category = SpellComponentCategory::Undef_SpellComponentCategory;
	DWORD _iconID = 0;
	SpellComponentType _type = SpellComponentType::Undef_SpellComponentType;
	unsigned int _gesture = 0;
	float _time = 0.0f;
	std::string _text;
	float _CDM = 0.0f;
};

class SpellComponentTable : public PackObj, public DBObj
{
public:
	SpellComponentTable();
	virtual ~SpellComponentTable();

	DECLARE_DBOBJ(SpellComponentTable)
	DECLARE_PACKABLE()
	DECLARE_LEGACY_PACK_MIGRATOR()

	static ITEM_TYPE GetTargetTypeFromComponentID(DWORD scid);
	const SpellComponentBase *InqSpellComponentBase(DWORD key);

	PackableHashTable<DWORD, SpellComponentBase> _spellComponentBaseHash;
};
