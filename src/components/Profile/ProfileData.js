import React from 'react';
import styled from 'styled-components';

import Box from '../UI/Box/Box';

const IdData = styled.div`
    margin: 15px;
`;
const ProfileData = (props) => {
    const information = props.data;
    let identityData = information.map((info) => {
        return (
            <Box key = {info.id} className="data">
                <p><span>{info.label}:</span> {info.value}</p>
            </Box>
        );
    })
    return(
        <IdData>
          {identityData}  
        </IdData>
    )
}

export default ProfileData;