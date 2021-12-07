#pragma once

// protocol
#pragma pack(push, 1)
struct PACKET
{
	unsigned char size;
	int		_id;
	int		_cmd;
};
#pragma pack(pop)