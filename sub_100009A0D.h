

__int64 __fastcall sub_100009A0D(_BYTE *a1, __int64 a2, const char *a3, __int64 a4, unsigned int a5)
{
  const char *v5; // r13
  __int64 v6; // rbx
  __int64 result; // rax
  unsigned int v8; // er15
  unsigned int v9; // er12
  __int64 v10; // r14
  unsigned int v11; // er14
  int v12; // er15
  int v13; // er12
  int v14; // ecx
  size_t v15; // rsi
  size_t v16; // rdx
  bool v17; // r15
  unsigned __int32 v18; // er12
  __int16 v19; // r15
  __int64 v20; // rbx
  __int16 v21; // ax
  signed __int64 v22; // [rsp+8h] [rbp-368h]
  signed __int64 v23; // [rsp+10h] [rbp-360h]
  int v24; // [rsp+20h] [rbp-350h]
  char v25; // [rsp+30h] [rbp-340h]
  char v26; // [rsp+133h] [rbp-23Dh]
  unsigned __int32 v27; // [rsp+140h] [rbp-230h]
  __int16 v28; // [rsp+144h] [rbp-22Ch]
  __int16 v29; // [rsp+146h] [rbp-22Ah]
  __int64 v30; // [rsp+340h] [rbp-30h]

  v5 = a3;
  v6 = a2;
  result = __stack_chk_guard;
  v8 = -1;
  if ( !a1 )
    goto LABEL_29;
  if ( a2 )
  {
    v8 = -3;
    if ( !a3 )
      goto LABEL_29;
    v8 = -4;
    if ( !a4 )
      goto LABEL_29;
    v9 = a5;
    v10 = __stack_chk_guard;
    if ( sub_10000FDBF(&v26, a4) )
    {
      v8 = -5;
      result = v10;
      v11 = v9;
      if ( v9 )
      {
        v12 = sub_10000FE58(&v25, 256LL, a2);
        v13 = strlen(v5);
        v14 = strlen(&v26);
        if ( v12 )
        {
          LODWORD(v15) = v12;
          v8 = -3;
          result = __stack_chk_guard;
          if ( !v13 )
            goto LABEL_29;
          v8 = -4;
          if ( !v14 )
            goto LABEL_29;
          v16 = v13;
          v15 = (signed int)v15;
          v8 = -2;
          if ( (unsigned __int64)(v13 + (signed __int64)(signed int)v15 + 4) > 0x400 )
            goto LABEL_29;
          v22 = v13 + (signed __int64)(signed int)v15 + 4;
          v24 = v14;
          v23 = v13 + 4LL;
          v17 = 1;
          if ( dword_10002AB90 )
          {
            printf("U = %s\n", v6);
            printf("K = %s\n", v5);
            printf("M = %s\n", &v26);
            printf("T = %08x\n", v11);
            v16 = v13;
            v17 = dword_10002AB90 == 0;
          }
          v18 = _byteswap_ulong(v11);
          v27 = v18;
          memcpy(&v28, v5, v16);
          memcpy((char *)&v27 + v23, &v25, v15);
          if ( !v17 )
          {
            puts("compute_checksum C1");
            sub_100001899((__int64)&v27, v22);
          }
          v19 = sub_100009DAF(&v27, v22);
          LOWORD(v27) = v19;
          memcpy((char *)&v27 + 2, &v26, v24);
          if ( dword_10002AB90 )
          {
            printf("C1=%04x\n", (unsigned __int16)__ROL2__(v19, 8));
            puts("compute_checksum C2");
            v20 = (unsigned int)(v24 + 2);
            sub_100001899((__int64)&v27, v20);
          }
          else
          {
            v20 = (unsigned int)(v24 + 2);
          }
          v21 = sub_100009DAF(&v27, v20);
          LOWORD(v27) = v18;
          HIWORD(v27) = v19;
          v28 = HIWORD(v18);
          v29 = v21;
          if ( dword_10002AB90 )
          {
            printf("C2=%04x\n", (unsigned __int16)__ROL2__(v21, 8));
            puts("Plaintext");
            sub_100001899((__int64)&v27, 8);
          }
          sub_1000115C7((__int64)(a1 + 1), 12, (__int64)&v27, 8);
          if ( dword_10002AB90 )
          {
            puts("Encrypt");
            sub_100001899((__int64)(a1 + 1), 12);
          }
          *a1 = 10;
          v8 = 0;
          if ( dword_10002AB90 )
            putchar(10);
        }
        else
        {
          v8 = -2;
        }
        result = __stack_chk_guard;
      }
    }
    else
    {
      result = v10;
    }
  }
  else
  {
    v8 = -2;
  }
LABEL_29:
  if ( result == v30 )
    result = v8;
  return result;
}
