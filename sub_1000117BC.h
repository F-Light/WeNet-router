__int64 __fastcall sub_1000117BC(__int64 a1, int a2, __int64 a3, signed int a4)
{
  signed int v4; // er14
  __int64 v5; // r15
  __int64 v6; // r12
  __int64 v7; // rbx
  unsigned __int64 v8; // rcx
  unsigned __int64 v9; // rax
  __int64 v10; // r9
  int v11; // edx
  char v12; // r8
  int v13; // ecx
  int v14; // esi
  unsigned int v15; // ecx
  bool v16; // zf
  __int64 v17; // rdi
  char v18; // dl
  unsigned int v19; // er15
  __int64 v20; // rsi
  char v21; // r12
  __int64 v22; // rsi
  __int64 v23; // rdx
  __int64 v24; // rax
  char v25; // r14
  char v26; // al
  __int64 v28; // [rsp+8h] [rbp-48h]
  __int64 v29; // [rsp+10h] [rbp-40h]
  __int64 v30; // [rsp+18h] [rbp-38h]
  signed int v31; // [rsp+24h] [rbp-2Ch]

  v4 = a4;
  v5 = a3;
  v6 = a1;
  LODWORD(v7) = -1;
  if ( a1 )
  {
    if ( a2 > 0 )
    {
      LODWORD(v7) = -2;
      if ( a3 )
      {
        if ( a4 > 0 )
        {
          v8 = (unsigned __int64)(1431655766LL * a4) >> 63;
          v9 = (unsigned __int64)(1431655766LL * v4) >> 32;
          if ( v4 != 3 * ((_DWORD)v9 + (_DWORD)v8) )
          {
LABEL_60:
            LODWORD(v7) = -4;
            return (unsigned int)v7;
          }
          LODWORD(v7) = -3;
          if ( 2 * ((signed int)v8 + (signed int)v9) <= a2 )
          {
            if ( dword_10002AB90 )
              puts("-----");
            v7 = 0LL;
            if ( v4 > 0 )
            {
              v10 = 0LL;
              while ( 1 )
              {
                LOBYTE(v11) = *(_BYTE *)(v5 + v7);
                if ( (unsigned __int8)(*(_BYTE *)(v5 + v7) - 97) >= 0x1Au
                  && (unsigned __int8)(v11 - 65) >= 0x1Au
                  && (unsigned __int8)(v11 - 48) >= 0xAu
                  && (unsigned __int8)v11 != 58
                  && (unsigned __int8)v11 != 95 )
                {
                  goto LABEL_60;
                }
                v12 = *(_BYTE *)(v7 + v5 + 1);
                if ( (unsigned __int8)(*(_BYTE *)(v7 + v5 + 1) - 97) >= 0x1Au
                  && (unsigned __int8)(v12 - 65) >= 0x1Au
                  && (unsigned __int8)(v12 - 48) >= 0xAu
                  && v12 != 58
                  && v12 != 95 )
                {
                  goto LABEL_60;
                }
                v13 = *(unsigned __int8 *)(v7 + v5 + 2);
                if ( v13 == 61 )
                {
                  v14 = (unsigned __int8)v11;
                  v15 = 0;
                  v16 = (unsigned __int8)v11 == 61;
                  v17 = 0LL;
                  v18 = 0;
                  if ( !v16 )
                  {
                    while ( (unsigned __int8)aAbcdefghijklmn[v17] != v14 )
                    {
                      ++v17;
                      v18 = -1;
                      if ( (unsigned int)v17 > 0x3F )
                        goto LABEL_36;
                    }
                    v18 = v17;
                  }
LABEL_36:
                  v22 = 0LL;
                  if ( v12 != 61 )
                  {
                    while ( aAbcdefghijklmn[v22] != v12 )
                    {
                      ++v22;
                      v15 = -1;
                      if ( (unsigned int)v22 > 0x3F )
                        goto LABEL_46;
                    }
                    v15 = v22;
                  }
LABEL_46:
                  *(_BYTE *)(v6 + v10) = 8 * v18 | (v15 >> 2) & 7;
                }
                else
                {
                  if ( (unsigned __int8)(v13 - 97) >= 0x1Au
                    && (unsigned __int8)(v13 - 65) >= 0x1Au
                    && (unsigned __int8)(v13 - 48) >= 0xAu
                    && (unsigned __int8)v13 != 58
                    && (unsigned __int8)v13 != 95 )
                  {
                    goto LABEL_60;
                  }
                  v29 = v6;
                  v30 = v5;
                  v11 = (unsigned __int8)v11;
                  v19 = 0;
                  v20 = 0LL;
                  v21 = 0;
                  if ( (unsigned __int8)v11 != 61 )
                  {
                    while ( (unsigned __int8)aAbcdefghijklmn[v20] != v11 )
                    {
                      ++v20;
                      v21 = -1;
                      if ( (unsigned int)v20 > 0x3F )
                        goto LABEL_41;
                    }
                    v21 = v20;
                  }
LABEL_41:
                  v28 = v10;
                  v23 = 0LL;
                  if ( v12 != 61 )
                  {
                    while ( aAbcdefghijklmn[v23] != v12 )
                    {
                      ++v23;
                      v19 = -1;
                      if ( (unsigned int)v23 > 0x3F )
                        goto LABEL_48;
                    }
                    v19 = v23;
                  }
LABEL_48:
                  v31 = v4;
                  v24 = 0LL;
                  while ( (unsigned __int8)aAbcdefghijklmn[v24] != (unsigned __int8)v13 )
                  {
                    ++v24;
                    v25 = -1;
                    if ( (unsigned int)v24 > 0x3F )
                      goto LABEL_53;
                  }
                  v25 = v24;
LABEL_53:
                  if ( dword_10002AB90 )
                    printf("%02x %02x %02x ", (unsigned int)v21, (unsigned int)(char)v19, (unsigned int)v25);
                  v26 = 8 * v21 | (v19 >> 2) & 7;
                  v6 = v29;
                  v10 = v28;
                  *(_BYTE *)(v29 + v28) = v26;
                  *(_BYTE *)(v29 + (v28 | 1)) = ((_BYTE)v19 << 6) | v25;
                  v4 = v31;
                  v5 = v30;
                }
                v7 += 3LL;
                v10 += 2LL;
                if ( (signed int)v7 >= v4 )
                {
                  LODWORD(v7) = v10;
                  break;
                }
              }
            }
            if ( dword_10002AB90 )
              puts("\n-----");
          }
        }
      }
    }
  }
  return (unsigned int)v7;
}