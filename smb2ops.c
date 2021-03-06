// SPDX-License-Identifier: GPL-2.0-or-later
/*
 *   Copyright (C) 2016 Namjae Jeon <linkinjeon@gmail.com>
 *   Copyright (C) 2018 Samsung Electronics Co., Ltd.
 */

#include <linux/slab.h>
#include "glob.h"
#include "smb2pdu.h"

#include "auth.h"
#include "transport_tcp.h"
#include "smb_common.h"

struct smb_version_values smb20_server_values = {
	.version_string = SMB20_VERSION_STRING,
	.protocol_id = SMB20_PROT_ID,
	.req_capabilities = 0, /* MBZ */
	.large_lock_type = 0,
	.exclusive_lock_type = SMB2_LOCKFLAG_EXCLUSIVE,
	.shared_lock_type = SMB2_LOCKFLAG_SHARED,
	.unlock_lock_type = SMB2_LOCKFLAG_UNLOCK,
	.header_size = sizeof(struct smb2_hdr),
	.max_header_size = MAX_SMB2_HDR_SIZE,
	.read_rsp_size = sizeof(struct smb2_read_rsp) - 1,
	.lock_cmd = SMB2_LOCK,
	.cap_unix = 0,
	.cap_nt_find = SMB2_NT_FIND,
	.cap_large_files = SMB2_LARGE_FILES,
	.create_lease_size = sizeof(struct create_lease),
	.create_durable_size = sizeof(struct create_durable_rsp),
	.create_mxac_size = sizeof(struct create_mxac_rsp),
	.create_disk_id_size = sizeof(struct create_disk_id_rsp),
};

struct smb_version_values smb21_server_values = {
	.version_string = SMB21_VERSION_STRING,
	.protocol_id = SMB21_PROT_ID,
	.req_capabilities = 0, /* MBZ */
	.large_lock_type = 0,
	.exclusive_lock_type = SMB2_LOCKFLAG_EXCLUSIVE,
	.shared_lock_type = SMB2_LOCKFLAG_SHARED,
	.unlock_lock_type = SMB2_LOCKFLAG_UNLOCK,
	.header_size = sizeof(struct smb2_hdr),
	.max_header_size = MAX_SMB2_HDR_SIZE,
	.read_rsp_size = sizeof(struct smb2_read_rsp) - 1,
	.lock_cmd = SMB2_LOCK,
	.cap_unix = 0,
	.cap_nt_find = SMB2_NT_FIND,
	.cap_large_files = SMB2_LARGE_FILES,
	.create_lease_size = sizeof(struct create_lease),
	.create_durable_size = sizeof(struct create_durable_rsp),
	.create_mxac_size = sizeof(struct create_mxac_rsp),
	.create_disk_id_size = sizeof(struct create_disk_id_rsp),
};

struct smb_version_values smb30_server_values = {
	.version_string = SMB30_VERSION_STRING,
	.protocol_id = SMB30_PROT_ID,
	.req_capabilities = SMB2_GLOBAL_CAP_DFS | SMB2_GLOBAL_CAP_LEASING
						| SMB2_GLOBAL_CAP_LARGE_MTU,
	.large_lock_type = 0,
	.exclusive_lock_type = SMB2_LOCKFLAG_EXCLUSIVE,
	.shared_lock_type = SMB2_LOCKFLAG_SHARED,
	.unlock_lock_type = SMB2_LOCKFLAG_UNLOCK,
	.header_size = sizeof(struct smb2_hdr),
	.max_header_size = MAX_SMB2_HDR_SIZE,
	.read_rsp_size = sizeof(struct smb2_read_rsp) - 1,
	.lock_cmd = SMB2_LOCK,
	.cap_unix = 0,
	.cap_nt_find = SMB2_NT_FIND,
	.cap_large_files = SMB2_LARGE_FILES,
	.create_lease_size = sizeof(struct create_lease),
	.create_durable_size = sizeof(struct create_durable_rsp),
	.create_durable_v2_size = sizeof(struct create_durable_v2_rsp),
	.create_mxac_size = sizeof(struct create_mxac_rsp),
	.create_disk_id_size = sizeof(struct create_disk_id_rsp),
};

struct smb_version_values smb302_server_values = {
	.version_string = SMB302_VERSION_STRING,
	.protocol_id = SMB302_PROT_ID,
	.req_capabilities = SMB2_GLOBAL_CAP_DFS | SMB2_GLOBAL_CAP_LEASING
						| SMB2_GLOBAL_CAP_LARGE_MTU,
	.large_lock_type = 0,
	.exclusive_lock_type = SMB2_LOCKFLAG_EXCLUSIVE,
	.shared_lock_type = SMB2_LOCKFLAG_SHARED,
	.unlock_lock_type = SMB2_LOCKFLAG_UNLOCK,
	.header_size = sizeof(struct smb2_hdr),
	.max_header_size = MAX_SMB2_HDR_SIZE,
	.read_rsp_size = sizeof(struct smb2_read_rsp) - 1,
	.lock_cmd = SMB2_LOCK,
	.cap_unix = 0,
	.cap_nt_find = SMB2_NT_FIND,
	.cap_large_files = SMB2_LARGE_FILES,
	.create_lease_size = sizeof(struct create_lease),
	.create_durable_size = sizeof(struct create_durable_rsp),
	.create_durable_v2_size = sizeof(struct create_durable_v2_rsp),
	.create_mxac_size = sizeof(struct create_mxac_rsp),
	.create_disk_id_size = sizeof(struct create_disk_id_rsp),
};

struct smb_version_values smb311_server_values = {
	.version_string = SMB311_VERSION_STRING,
	.protocol_id = SMB311_PROT_ID,
	.req_capabilities = SMB2_GLOBAL_CAP_DFS | SMB2_GLOBAL_CAP_LEASING
						| SMB2_GLOBAL_CAP_LARGE_MTU,
	.large_lock_type = 0,
	.exclusive_lock_type = SMB2_LOCKFLAG_EXCLUSIVE,
	.shared_lock_type = SMB2_LOCKFLAG_SHARED,
	.unlock_lock_type = SMB2_LOCKFLAG_UNLOCK,
	.header_size = sizeof(struct smb2_hdr),
	.max_header_size = MAX_SMB2_HDR_SIZE,
	.read_rsp_size = sizeof(struct smb2_read_rsp) - 1,
	.lock_cmd = SMB2_LOCK,
	.cap_unix = 0,
	.cap_nt_find = SMB2_NT_FIND,
	.cap_large_files = SMB2_LARGE_FILES,
	.create_lease_size = sizeof(struct create_lease),
	.create_durable_size = sizeof(struct create_durable_rsp),
	.create_durable_v2_size = sizeof(struct create_durable_v2_rsp),
	.create_mxac_size = sizeof(struct create_mxac_rsp),
	.create_disk_id_size = sizeof(struct create_disk_id_rsp),
};

struct smb_version_ops smb2_0_server_ops = {
	.get_cmd_val		=	get_smb2_cmd_val,
	.init_rsp_hdr		=	init_smb2_rsp_hdr,
	.set_rsp_status		=	set_smb2_rsp_status,
	.allocate_rsp_buf       =       smb2_allocate_rsp_buf,
	.set_rsp_credits        =       smb2_set_rsp_credits,
	.check_user_session	=	smb2_check_user_session,
	.get_cifsd_tcon		=	smb2_get_cifsd_tcon,
	.is_sign_req		=	smb2_is_sign_req,
	.check_sign_req		=	smb2_check_sign_req,
	.set_sign_rsp		=	smb2_set_sign_rsp
};

struct smb_version_ops smb3_0_server_ops = {
	.get_cmd_val		=	get_smb2_cmd_val,
	.init_rsp_hdr		=	init_smb2_rsp_hdr,
	.set_rsp_status		=	set_smb2_rsp_status,
	.allocate_rsp_buf       =       smb2_allocate_rsp_buf,
	.set_rsp_credits        =       smb2_set_rsp_credits,
	.check_user_session	=	smb2_check_user_session,
	.get_cifsd_tcon		=	smb2_get_cifsd_tcon,
	.is_sign_req		=	smb2_is_sign_req,
	.check_sign_req		=	smb3_check_sign_req,
	.set_sign_rsp		=	smb3_set_sign_rsp,
	.generate_signingkey	=	cifsd_gen_smb30_signingkey,
	.generate_encryptionkey	=	cifsd_gen_smb30_encryptionkey,
	.is_transform_hdr	=	smb3_is_transform_hdr,
	.decrypt_req		=	smb3_decrypt_req,
	.encrypt_resp		=	smb3_encrypt_resp
};

struct smb_version_ops smb3_11_server_ops = {
	.get_cmd_val		=	get_smb2_cmd_val,
	.init_rsp_hdr		=	init_smb2_rsp_hdr,
	.set_rsp_status		=	set_smb2_rsp_status,
	.allocate_rsp_buf       =       smb2_allocate_rsp_buf,
	.set_rsp_credits        =       smb2_set_rsp_credits,
	.check_user_session	=	smb2_check_user_session,
	.get_cifsd_tcon		=	smb2_get_cifsd_tcon,
	.is_sign_req		=	smb2_is_sign_req,
	.check_sign_req		=	smb3_check_sign_req,
	.set_sign_rsp		=	smb3_set_sign_rsp,
	.generate_signingkey	=	cifsd_gen_smb311_signingkey,
	.generate_encryptionkey	=	cifsd_gen_smb311_encryptionkey,
	.is_transform_hdr	=	smb3_is_transform_hdr,
	.decrypt_req		=	smb3_decrypt_req,
	.encrypt_resp		=	smb3_encrypt_resp
};

struct smb_version_cmds smb2_0_server_cmds[NUMBER_OF_SMB2_COMMANDS] = {
	[SMB2_NEGOTIATE_HE]	=	{ .proc = smb2_negotiate_request, },
	[SMB2_SESSION_SETUP_HE] =	{ .proc = smb2_sess_setup, },
	[SMB2_TREE_CONNECT_HE]  =	{ .proc = smb2_tree_connect,},
	[SMB2_TREE_DISCONNECT_HE]  =	{ .proc = smb2_tree_disconnect,},
	[SMB2_LOGOFF_HE]	=	{ .proc = smb2_session_logoff,},
	[SMB2_CREATE_HE]	=	{ .proc = smb2_open},
	[SMB2_QUERY_INFO_HE]	=	{ .proc = smb2_query_info},
	[SMB2_QUERY_DIRECTORY_HE] =	{ .proc = smb2_query_dir},
	[SMB2_CLOSE_HE]		=	{ .proc = smb2_close},
	[SMB2_ECHO_HE]		=	{ .proc = smb2_echo},
	[SMB2_SET_INFO_HE]      =       { .proc = smb2_set_info},
	[SMB2_READ_HE]		=	{ .proc = smb2_read},
	[SMB2_WRITE_HE]		=	{ .proc = smb2_write},
	[SMB2_FLUSH_HE]		=	{ .proc = smb2_flush},
	[SMB2_CANCEL_HE]	=	{ .proc = smb2_cancel},
	[SMB2_LOCK_HE]		=	{ .proc = smb2_lock},
	[SMB2_IOCTL_HE]		=	{ .proc = smb2_ioctl},
	[SMB2_OPLOCK_BREAK_HE]	=	{ .proc = smb2_oplock_break},
	[SMB2_CHANGE_NOTIFY_HE]	=	{ .proc = smb2_notify},
};

#ifdef CONFIG_CIFS_INSECURE_SERVER
/**
 * init_smb2_0_server() - initialize a smb server connection with smb2.0
 *			command dispatcher
 * @conn:	TCP server instance of connection
 */
int init_smb2_0_server(struct cifsd_tcp_conn *conn)
{
	conn->vals = &smb20_server_values;
	conn->ops = &smb2_0_server_ops;
	conn->cmds = smb2_0_server_cmds;
	conn->max_cmds = ARRAY_SIZE(smb2_0_server_cmds);
	conn->max_credits = SMB2_MAX_CREDITS;
	conn->credits_granted = 0;
	conn->srv_cap = 0;
	return 0;
}
#else
int init_smb2_0_server(struct cifsd_tcp_conn *conn)
{
	return -ENOTSUPP;
}
#endif

/**
 * init_smb2_1_server() - initialize a smb server connection with smb2.1
 *			command dispatcher
 * @conn:	TCP server instance of connection
 */
void init_smb2_1_server(struct cifsd_tcp_conn *conn)
{
	conn->vals = &smb21_server_values;
	conn->ops = &smb2_0_server_ops;
	conn->cmds = smb2_0_server_cmds;
	conn->max_cmds = ARRAY_SIZE(smb2_0_server_cmds);
	conn->max_credits = SMB2_MAX_CREDITS;
	conn->srv_cap = SMB2_GLOBAL_CAP_LARGE_MTU;

	if (lease_enable)
		conn->srv_cap |= SMB2_GLOBAL_CAP_LEASING;
}

/**
 * init_smb3_0_server() - initialize a smb server connection with smb3.0
 *			command dispatcher
 * @conn:	TCP server instance of connection
 */
void init_smb3_0_server(struct cifsd_tcp_conn *conn)
{
	conn->vals = &smb30_server_values;
	conn->ops = &smb3_0_server_ops;
	conn->cmds = smb2_0_server_cmds;
	conn->max_cmds = ARRAY_SIZE(smb2_0_server_cmds);
	conn->max_credits = SMB2_MAX_CREDITS;
	conn->srv_cap = SMB2_GLOBAL_CAP_LARGE_MTU;

	if (lease_enable)
		conn->srv_cap |= SMB2_GLOBAL_CAP_LEASING;

	if (multi_channel_enable)
		conn->srv_cap |= SMB2_GLOBAL_CAP_MULTI_CHANNEL;

	if (encryption_enable && conn->cli_cap & SMB2_GLOBAL_CAP_ENCRYPTION)
		conn->srv_cap |= SMB2_GLOBAL_CAP_ENCRYPTION;
}

/**
 * init_smb3_02_server() - initialize a smb server connection with smb3.02
 *			command dispatcher
 * @conn:	TCP server instance of connection
 */
void init_smb3_02_server(struct cifsd_tcp_conn *conn)
{
	conn->vals = &smb302_server_values;
	conn->ops = &smb3_0_server_ops;
	conn->cmds = smb2_0_server_cmds;
	conn->max_cmds = ARRAY_SIZE(smb2_0_server_cmds);
	conn->max_credits = SMB2_MAX_CREDITS;
	conn->srv_cap = SMB2_GLOBAL_CAP_LARGE_MTU;

	if (lease_enable)
		conn->srv_cap |= SMB2_GLOBAL_CAP_LEASING;

	if (multi_channel_enable)
		conn->srv_cap |= SMB2_GLOBAL_CAP_MULTI_CHANNEL;

	if (encryption_enable && conn->cli_cap & SMB2_GLOBAL_CAP_ENCRYPTION)
		conn->srv_cap |= SMB2_GLOBAL_CAP_ENCRYPTION;
}

/**
 * init_smb3_11_server() - initialize a smb server connection with smb3.11
 *			command dispatcher
 * @conn:	TCP server instance of connection
 */
int init_smb3_11_server(struct cifsd_tcp_conn *conn)
{
	conn->vals = &smb311_server_values;
	conn->ops = &smb3_11_server_ops;
	conn->cmds = smb2_0_server_cmds;
	conn->max_cmds = ARRAY_SIZE(smb2_0_server_cmds);
	conn->max_credits = SMB2_MAX_CREDITS;
	conn->srv_cap = SMB2_GLOBAL_CAP_LARGE_MTU;

	if (lease_enable)
		conn->srv_cap |= SMB2_GLOBAL_CAP_LEASING;

	if (multi_channel_enable)
		conn->srv_cap |= SMB2_GLOBAL_CAP_MULTI_CHANNEL;

	if (conn->preauth_info->CipherId)
		conn->srv_cap |= SMB2_GLOBAL_CAP_ENCRYPTION;

	INIT_LIST_HEAD(&conn->preauth_sess_table);
	return 0;
}
