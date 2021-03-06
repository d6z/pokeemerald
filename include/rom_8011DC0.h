#ifndef GUARD_rom_8011DC0_H
#define GUARD_rom_8011DC0_H

// Exported type declarations

// Exported RAM declarations

extern u8 gUnknown_02022C2C;
extern struct UnkLinkRfuStruct_02022B14Substruct gUnknown_02022C38;
extern u16 gUnknown_02022C3C;
extern u8 gUnknown_02022C3E;

// Exported ROM declarations

void sub_8018438(void);
void sub_801B990(u32, u32);
u8 sub_8013F78(void);
bool32 sub_802C908(u16);
void nullsub_89(u8 taskId);
void var_800D_set_xB(void);

bool32 mevent_0814257C(u8 *textState, const u8 *str);
void sub_8018884(const u8 *src);
void sub_80186A4(void);

#endif //GUARD_rom_8011DC0_H
