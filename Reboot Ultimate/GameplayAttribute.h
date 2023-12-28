#pragma once

struct FGameplayAttribute
{
	FString AttributeName;
	void* Attribute; // Property
	UStruct* AttributeOwner;

	std::string GetAttributeName()
	{
		return AttributeName.ToString();
	}

	std::string GetAttributePropertyName()
	{
		if (!Attribute)
			return "INVALIDATTRIBUTE";

		return GetFNameOfProp(Attribute)->ToString();
	}
};