/*
 * CPU features/facilities for s390
 *
 * Copyright 2016 IBM Corp.
 *
 * Author(s): Michael Mueller <mimu@linux.vnet.ibm.com>
 *            David Hildenbrand <dahi@linux.vnet.ibm.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or (at
 * your option) any later version. See the COPYING file in the top-level
 * directory.
 */

#ifndef TARGET_S390X_CPU_FEATURES_H
#define TARGET_S390X_CPU_FEATURES_H

#include "qemu/bitmap.h"

typedef enum {
    S390_FEAT_N3 = 0,
    S390_FEAT_ZARCH,
    S390_FEAT_DAT_ENH_1,
    S390_FEAT_IDTE_SEGMENT,
    S390_FEAT_IDTE_REGION,
    S390_FEAT_ASN_LX_REUSE,
    S390_FEAT_STFLE,
    S390_FEAT_EDAT_1,
    S390_FEAT_SENSE_RUNNING_STATUS,
    S390_FEAT_CONDITIONAL_SSKE,
    S390_FEAT_CONFIGURATION_TOPOLOGY,
    S390_FEAT_IPTE_RANGE,
    S390_FEAT_NONQ_KEY_SETTING,
    S390_FEAT_EXTENDED_TRANSLATION_2,
    S390_FEAT_MSA,
    S390_FEAT_LONG_DISPLACEMENT,
    S390_FEAT_LONG_DISPLACEMENT_FAST,
    S390_FEAT_HFP_MADDSUB,
    S390_FEAT_EXTENDED_IMMEDIATE,
    S390_FEAT_EXTENDED_TRANSLATION_3,
    S390_FEAT_HFP_UNNORMALIZED_EXT,
    S390_FEAT_ETF2_ENH,
    S390_FEAT_STORE_CLOCK_FAST,
    S390_FEAT_PARSING_ENH,
    S390_FEAT_MOVE_WITH_OPTIONAL_SPEC,
    S390_FEAT_TOD_CLOCK_STEERING,
    S390_FEAT_ETF3_ENH,
    S390_FEAT_EXTRACT_CPU_TIME,
    S390_FEAT_COMPARE_AND_SWAP_AND_STORE,
    S390_FEAT_COMPARE_AND_SWAP_AND_STORE_2,
    S390_FEAT_GENERAL_INSTRUCTIONS_EXT,
    S390_FEAT_EXECUTE_EXT,
    S390_FEAT_ENHANCED_MONITOR,
    S390_FEAT_FLOATING_POINT_EXT,
    S390_FEAT_SET_PROGRAM_PARAMETERS,
    S390_FEAT_FLOATING_POINT_SUPPPORT_ENH,
    S390_FEAT_DFP,
    S390_FEAT_DFP_FAST,
    S390_FEAT_PFPO,
    S390_FEAT_GEN11_ENH,
    S390_FEAT_CMPSC_ENH,
    S390_FEAT_DFP_ZONED_CONVERSION,
    S390_FEAT_GEN12_ENH,
    S390_FEAT_CONSTRAINT_TRANSACTIONAL_EXE,
    S390_FEAT_LOCAL_TLB_CLEARING,
    S390_FEAT_INTERLOCKED_ACCESS_2,
    S390_FEAT_GEN13_ENH,
    S390_FEAT_MSA_EXT_5,
    S390_FEAT_RUNTIME_INSTRUMENTATION,
    S390_FEAT_TRANSACTIONAL_EXE,
    S390_FEAT_STORE_HYPERVISOR_INFO,
    S390_FEAT_ACCESS_EXCEPTION_FS_INDICATION,
    S390_FEAT_MSA_EXT_3,
    S390_FEAT_MSA_EXT_4,
    S390_FEAT_EDAT_2,
    S390_FEAT_DFP_PACKED_CONVERSION,
    S390_FEAT_VECTOR,
    S390_FEAT_STORE_CPU_COUNTER_MULTI,
    S390_FEAT_SIE_GSLS,
    S390_FEAT_ESOP,
    S390_FEAT_SIE_64BSCAO,
    S390_FEAT_SIE_CMMA,
    S390_FEAT_SIE_PFMFI,
    S390_FEAT_SIE_IBS,
    S390_FEAT_SIE_F2,
    S390_FEAT_SIE_SKEY,
    S390_FEAT_SIE_GPERE,
    S390_FEAT_SIE_SIIF,
    S390_FEAT_SIE_SIGPIF,
    S390_FEAT_SIE_IB,
    S390_FEAT_SIE_CEI,
    S390_FEAT_DAT_ENH_2,
    S390_FEAT_CMM,
    S390_FEAT_PLO_CL,
    S390_FEAT_PLO_CLG,
    S390_FEAT_PLO_CLGR,
    S390_FEAT_PLO_CLX,
    S390_FEAT_PLO_CS,
    S390_FEAT_PLO_CSG,
    S390_FEAT_PLO_CSGR,
    S390_FEAT_PLO_CSX,
    S390_FEAT_PLO_DCS,
    S390_FEAT_PLO_DCSG,
    S390_FEAT_PLO_DCSGR,
    S390_FEAT_PLO_DCSX,
    S390_FEAT_PLO_CSST,
    S390_FEAT_PLO_CSSTG,
    S390_FEAT_PLO_CSSTGR,
    S390_FEAT_PLO_CSSTX,
    S390_FEAT_PLO_CSDST,
    S390_FEAT_PLO_CSDSTG,
    S390_FEAT_PLO_CSDSTGR,
    S390_FEAT_PLO_CSDSTX,
    S390_FEAT_PLO_CSTST,
    S390_FEAT_PLO_CSTSTG,
    S390_FEAT_PLO_CSTSTGR,
    S390_FEAT_PLO_CSTSTX,
    S390_FEAT_PTFF_QTO,
    S390_FEAT_PTFF_QSI,
    S390_FEAT_PTFF_QPT,
    S390_FEAT_PTFF_QUI,
    S390_FEAT_PTFF_QTOU,
    S390_FEAT_PTFF_STO,
    S390_FEAT_PTFF_STOU,
    S390_FEAT_KMAC_DEA,
    S390_FEAT_KMAC_TDEA_128,
    S390_FEAT_KMAC_TDEA_192,
    S390_FEAT_KMAC_EDEA,
    S390_FEAT_KMAC_ETDEA_128,
    S390_FEAT_KMAC_ETDEA_192,
    S390_FEAT_KMAC_AES_128,
    S390_FEAT_KMAC_AES_192,
    S390_FEAT_KMAC_AES_256,
    S390_FEAT_KMAC_EAES_128,
    S390_FEAT_KMAC_EAES_192,
    S390_FEAT_KMAC_EAES_256,
    S390_FEAT_KMC_DEA,
    S390_FEAT_KMC_TDEA_128,
    S390_FEAT_KMC_TDEA_192,
    S390_FEAT_KMC_EDEA,
    S390_FEAT_KMC_ETDEA_128,
    S390_FEAT_KMC_ETDEA_192,
    S390_FEAT_KMC_AES_128,
    S390_FEAT_KMC_AES_192,
    S390_FEAT_KMC_AES_256,
    S390_FEAT_KMC_EAES_128,
    S390_FEAT_KMC_EAES_192,
    S390_FEAT_KMC_EAES_256,
    S390_FEAT_KMC_PRNG,
    S390_FEAT_KM_DEA,
    S390_FEAT_KM_TDEA_128,
    S390_FEAT_KM_TDEA_192,
    S390_FEAT_KM_EDEA,
    S390_FEAT_KM_ETDEA_128,
    S390_FEAT_KM_ETDEA_192,
    S390_FEAT_KM_AES_128,
    S390_FEAT_KM_AES_192,
    S390_FEAT_KM_AES_256,
    S390_FEAT_KM_EAES_128,
    S390_FEAT_KM_EAES_192,
    S390_FEAT_KM_EAES_256,
    S390_FEAT_KM_XTS_AES_128,
    S390_FEAT_KM_XTS_AES_256,
    S390_FEAT_KM_XTS_EAES_128,
    S390_FEAT_KM_XTS_EAES_256,
    S390_FEAT_KIMD_SHA_1,
    S390_FEAT_KIMD_SHA_256,
    S390_FEAT_KIMD_SHA_512,
    S390_FEAT_KIMD_GHASH,
    S390_FEAT_KLMD_SHA_1,
    S390_FEAT_KLMD_SHA_256,
    S390_FEAT_KLMD_SHA_512,
    S390_FEAT_PCKMO_EDEA,
    S390_FEAT_PCKMO_ETDEA_128,
    S390_FEAT_PCKMO_ETDEA_256,
    S390_FEAT_PCKMO_AES_128,
    S390_FEAT_PCKMO_AES_192,
    S390_FEAT_PCKMO_AES_256,
    S390_FEAT_KMCTR_DEA,
    S390_FEAT_KMCTR_TDEA_128,
    S390_FEAT_KMCTR_TDEA_192,
    S390_FEAT_KMCTR_EDEA,
    S390_FEAT_KMCTR_ETDEA_128,
    S390_FEAT_KMCTR_ETDEA_192,
    S390_FEAT_KMCTR_AES_128,
    S390_FEAT_KMCTR_AES_192,
    S390_FEAT_KMCTR_AES_256,
    S390_FEAT_KMCTR_EAES_128,
    S390_FEAT_KMCTR_EAES_192,
    S390_FEAT_KMCTR_EAES_256,
    S390_FEAT_KMF_DEA,
    S390_FEAT_KMF_TDEA_128,
    S390_FEAT_KMF_TDEA_192,
    S390_FEAT_KMF_EDEA,
    S390_FEAT_KMF_ETDEA_128,
    S390_FEAT_KMF_ETDEA_192,
    S390_FEAT_KMF_AES_128,
    S390_FEAT_KMF_AES_192,
    S390_FEAT_KMF_AES_256,
    S390_FEAT_KMF_EAES_128,
    S390_FEAT_KMF_EAES_192,
    S390_FEAT_KMF_EAES_256,
    S390_FEAT_KMO_DEA,
    S390_FEAT_KMO_TDEA_128,
    S390_FEAT_KMO_TDEA_192,
    S390_FEAT_KMO_EDEA,
    S390_FEAT_KMO_ETDEA_128,
    S390_FEAT_KMO_ETDEA_192,
    S390_FEAT_KMO_AES_128,
    S390_FEAT_KMO_AES_192,
    S390_FEAT_KMO_AES_256,
    S390_FEAT_KMO_EAES_128,
    S390_FEAT_KMO_EAES_192,
    S390_FEAT_KMO_EAES_256,
    S390_FEAT_PCC_CMAC_DEA,
    S390_FEAT_PCC_CMAC_TDEA_128,
    S390_FEAT_PCC_CMAC_TDEA_192,
    S390_FEAT_PCC_CMAC_ETDEA_128,
    S390_FEAT_PCC_CMAC_ETDEA_192,
    S390_FEAT_PCC_CMAC_TDEA,
    S390_FEAT_PCC_CMAC_AES_128,
    S390_FEAT_PCC_CMAC_AES_192,
    S390_FEAT_PCC_CMAC_AES_256,
    S390_FEAT_PCC_CMAC_EAES_128,
    S390_FEAT_PCC_CMAC_EAES_192,
    S390_FEAT_PCC_CMAC_EAES_256,
    S390_FEAT_PCC_XTS_AES_128,
    S390_FEAT_PCC_XTS_AES_256,
    S390_FEAT_PCC_XTS_EAES_128,
    S390_FEAT_PCC_XTS_EAES_256,
    S390_FEAT_PPNO_SHA_512_DRNG,
    S390_FEAT_MAX,
} S390Feat;

/* CPU features are announced via different ways */
typedef enum {
    S390_FEAT_TYPE_STFL,
    S390_FEAT_TYPE_SCLP_CONF_CHAR,
    S390_FEAT_TYPE_SCLP_CONF_CHAR_EXT,
    S390_FEAT_TYPE_SCLP_CPU,
    S390_FEAT_TYPE_MISC,
    S390_FEAT_TYPE_PLO,
    S390_FEAT_TYPE_PTFF,
    S390_FEAT_TYPE_KMAC,
    S390_FEAT_TYPE_KMC,
    S390_FEAT_TYPE_KM,
    S390_FEAT_TYPE_KIMD,
    S390_FEAT_TYPE_KLMD,
    S390_FEAT_TYPE_PCKMO,
    S390_FEAT_TYPE_KMCTR,
    S390_FEAT_TYPE_KMF,
    S390_FEAT_TYPE_KMO,
    S390_FEAT_TYPE_PCC,
    S390_FEAT_TYPE_PPNO,
} S390FeatType;

/* Definition of a CPU feature */
typedef struct {
    const char *name;       /* name exposed to the user */
    const char *desc;       /* description exposed to the user */
    S390FeatType type;      /* feature type (way of indication)*/
    int bit;                /* bit within the feature type area (fixed) */
} S390FeatDef;

/* use ordinary bitmap operations to work with features */
typedef unsigned long S390FeatBitmap[BITS_TO_LONGS(S390_FEAT_MAX)];

const S390FeatDef *s390_feat_def(S390Feat feat);
S390Feat s390_feat_by_type_and_bit(S390FeatType type, int bit);
void s390_fill_feat_block(const S390FeatBitmap features, S390FeatType type,
                          uint8_t *data);
void s390_add_from_feat_block(S390FeatBitmap features, S390FeatType type,
                          uint8_t *data);
void s390_feat_bitmap_to_ascii(const S390FeatBitmap features, void *opaque,
                               void (*fn)(const char *name, void *opaque));

/* static groups that will never change */
typedef enum {
    S390_FEAT_GROUP_PLO,
    S390_FEAT_GROUP_TOD_CLOCK_STEERING,
    S390_FEAT_GROUP_GEN13_PTFF_ENH,
    S390_FEAT_GROUP_MSA,
    S390_FEAT_GROUP_MSA_EXT_1,
    S390_FEAT_GROUP_MSA_EXT_2,
    S390_FEAT_GROUP_MSA_EXT_3,
    S390_FEAT_GROUP_MSA_EXT_4,
    S390_FEAT_GROUP_MSA_EXT_5,
    S390_FEAT_GROUP_MAX,
} S390FeatGroup;

/* Definition of a CPU feature group */
typedef struct {
    const char *name;       /* name exposed to the user */
    const char *desc;       /* description exposed to the user */
    S390FeatBitmap feat;    /* features contained in the group */
} S390FeatGroupDef;

const S390FeatGroupDef *s390_feat_group_def(S390FeatGroup group);

#define BE_BIT_NR(BIT) (BIT ^ (BITS_PER_LONG - 1))
#define BE_BIT(BIT) (1ULL < BE_BIT_NR(BIT))

#endif /* TARGET_S390X_CPU_FEATURES_H */
