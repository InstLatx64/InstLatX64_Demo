#pragma once

#define _AMX_CONFIG_RESERVED_SIZE	14
#define _AMX_VEX_MAX_REGISTERS		16

void AMX_Test(void);

// Intel Architecture Instruction Set Extensions and Future Features
// Programming Reference May 2021 319433-044 p. 100
//	format of memory payload. each field is a byte.
//		 0: palette_id
//		 1: startRow (8b)
//	 2-15: reserved (must be zero)
//	16-17: tile0.colsb -- bytes_per_row
//	18-19: tile1.colsb
//	20-21: tile2.colsb
//			...
//	46-47: tile15.colsb
//		48: tile0.rows
//		49: tile1.rows
//		50: tile2.rows
//			 ...
//		63: tile15.rows

class XTILECFG {
	unsigned char	palette_id;
	unsigned char	startRow;
	unsigned char	reserved[_AMX_CONFIG_RESERVED_SIZE];
	unsigned short	tile_cols[_AMX_VEX_MAX_REGISTERS];
	unsigned char	tile_rows[_AMX_VEX_MAX_REGISTERS];
public:
	XTILECFG() {
		memset(this, 0, sizeof(XTILECFG));
	};
	XTILECFG(unsigned int c, unsigned int r, unsigned int tilesize, unsigned int maxreg, unsigned int p = 1) : palette_id(p), startRow(0) {
		memset(reserved, 0, _AMX_CONFIG_RESERVED_SIZE);
		for (unsigned int i = 0, ts = tilesize; (i < _AMX_VEX_MAX_REGISTERS); i++) {
			if ((i < maxreg) && (ts >= c * r)) {
				tile_cols[i] = c;
				tile_rows[i] = r;
			} else {
				tile_cols[i] = 0;
				tile_rows[i] = 0;
			}
			//std::cout << i << ' ' << ts << ' ' << c * r << std::endl;
			ts = ts >= (c * r) ? ts - (c * r) : 0;
		}
	};
	void XTILECFG_reg(unsigned int c, unsigned int r, unsigned int reg) {
		tile_cols[reg] = c;
		tile_rows[reg] = r;
	}
};
