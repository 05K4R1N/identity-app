import React from 'react';

import Box from '../UI/Box/Box';

const ProfileData = (props) => {
    const information = props.data;
    let identityData = information.map((info) => {
        return (
            <div key = {info.id}>
                <p><span>{info.label}:</span> {info.value}</p>
            </div>
        );
    })
    return(
        <Box>
          {identityData}  
        </Box>
    )
}

export default ProfileData;